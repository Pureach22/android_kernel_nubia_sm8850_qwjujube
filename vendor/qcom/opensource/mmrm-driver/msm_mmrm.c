/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <linux/soc/qcom/msm_mmrm.h>

static DEFINE_MUTEX(mmrm_lock);
static LIST_HEAD(mmrm_clients);
static bool mmrm_probed;

struct mmrm_client {
	struct list_head list;
	struct mmrm_client_desc desc;
	u64 voted_rate;
};

struct mmrm_client *mmrm_client_register(struct mmrm_client_desc *desc)
{
	struct mmrm_client *client;

	if (!desc) {
		pr_err("mmrm: invalid client desc\n");
		return NULL;
	}

	client = kzalloc(sizeof(*client), GFP_KERNEL);
	if (!client)
		return NULL;

	memcpy(&client->desc, desc, sizeof(*desc));

	mutex_lock(&mmrm_lock);
	list_add_tail(&client->list, &mmrm_clients);
	mutex_unlock(&mmrm_lock);

	pr_info("mmrm: registered client %s (domain:%d, id:%d, clk:%pK)\n",
		desc->client_info.desc.name,
		desc->client_info.desc.client_domain,
		desc->client_info.desc.client_id,
		desc->client_info.desc.clk);

	return client;
}
EXPORT_SYMBOL(mmrm_client_register);

int mmrm_client_deregister(struct mmrm_client *client)
{
	if (!client) {
		pr_err("mmrm: invalid client for deregister\n");
		return -EINVAL;
	}

	mutex_lock(&mmrm_lock);
	list_del(&client->list);
	mutex_unlock(&mmrm_lock);

	pr_info("mmrm: deregistered client %s\n", client->desc.client_info.desc.name);
	kfree(client);

	return 0;
}
EXPORT_SYMBOL(mmrm_client_deregister);

int mmrm_client_set_value(struct mmrm_client *client, struct mmrm_client_data *data, u64 rate)
{
	int ret = 0;
	struct clk *clk;

	if (!client) {
		pr_err("mmrm: invalid client for set_value\n");
		return -EINVAL;
	}

	clk = client->desc.client_info.desc.clk;
	if (clk) {
		ret = clk_set_rate(clk, rate);
		if (ret) {
			pr_err("mmrm: clk_set_rate failed for %s to %llu Hz: %d\n",
				client->desc.client_info.desc.name, rate, ret);
		} else {
			pr_debug("mmrm: set_rate for %s to %llu Hz\n",
				client->desc.client_info.desc.name, rate);
		}
	}

	client->voted_rate = rate;
	return ret;
}
EXPORT_SYMBOL(mmrm_client_set_value);

int mmrm_client_set_value_in_range(struct mmrm_client *client, struct mmrm_client_data *data, struct mmrm_client_res_value *val)
{
	if (!val)
		return -EINVAL;
	return mmrm_client_set_value(client, data, val->cur);
}
EXPORT_SYMBOL(mmrm_client_set_value_in_range);

int mmrm_client_get_value(struct mmrm_client *client, struct mmrm_client_data *data, u64 *rate)
{
	if (!client || !rate)
		return -EINVAL;
	*rate = client->voted_rate;
	return 0;
}
EXPORT_SYMBOL(mmrm_client_get_value);

static u32 mmrm_clk_count = 0;

int mmrm_client_get_clk_count(void)
{
	return mmrm_clk_count;
}
EXPORT_SYMBOL(mmrm_client_get_clk_count);

bool mmrm_client_check_scaling_supported(enum mmrm_client_type type, u32 id)
{
	return true;
}
EXPORT_SYMBOL(mmrm_client_check_scaling_supported);

static int msm_mmrm_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct property *prop;

	if (np) {
		prop = of_find_property(np, "mmrm-client-info", NULL);
		if (prop) {
			mmrm_clk_count = prop->length / 20;
		}
	}

	pr_info("mmrm: platform driver probed successfully, mmrm_clk_count = %u\n", mmrm_clk_count);
	mmrm_probed = true;
	return 0;
}

static void msm_mmrm_remove(struct platform_device *pdev)
{
	mmrm_probed = false;
	pr_info("mmrm: platform driver removed\n");
}

static const struct of_device_id msm_mmrm_dt_match[] = {
	{ .compatible = "qcom,msm-mmrm" },
	{ .compatible = "qcom,canoe-mmrm" },
	{ }
};
MODULE_DEVICE_TABLE(of, msm_mmrm_dt_match);

static struct platform_driver msm_mmrm_driver = {
	.probe = msm_mmrm_probe,
	.remove = msm_mmrm_remove,
	.driver = {
		.name = "msm_mmrm",
		.of_match_table = msm_mmrm_dt_match,
	},
};

static int __init msm_mmrm_init(void)
{
	return platform_driver_register(&msm_mmrm_driver);
}

static void __exit msm_mmrm_exit(void)
{
	platform_driver_unregister(&msm_mmrm_driver);
}

module_init(msm_mmrm_init);
module_exit(msm_mmrm_exit);

MODULE_DESCRIPTION("Qualcomm Multi-Media Resource Manager (MMRM) Driver - Antigravity MMRM Custom");
MODULE_VERSION("Antigravity-MMRM-v1.2");
MODULE_LICENSE("GPL v2");
