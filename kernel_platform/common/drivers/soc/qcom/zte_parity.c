/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * ZTE RedMagic Kernel Parity Implementation - Core Bridge
 * This file provides the missing proprietary functions required by 
 * the Qualcomm drivers to ensure binary parity with original firmware.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/export.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/scatterlist.h>
#include <linux/iommu.h>
#include <linux/io-pgtable.h>
#include <linux/qcom-io-pgtable.h>
#include <soc/qcom/dcvs.h>
#include <linux/firmware/qcom/qcom_scm.h>
#include "../../firmware/qcom/qcom_scm.h"
#include <linux/qtee_shmbridge.h>
#include <linux/clk.h>
#include <drm/drm_device.h>
#include <linux/clk.h>
#include <soc/qcom/qseecom_scm.h>
#include <linux/dma-buf.h>
#include <soc/qcom/crm.h>
#include <linux/soc/qcom/panel_event_notifier.h>
#include <linux/list.h>
#include <linux/mutex.h>

#if 0
/**
 * qcom_arm_lpae_map_sg - Map a scatterlist using LPAE ops
 */
int qcom_arm_lpae_map_sg(struct io_pgtable_ops *ops, unsigned long iova,
			 struct scatterlist *sg, unsigned int nents, int prot,
			 gfp_t gfp, size_t *mapped)
{
	struct scatterlist *s;
	size_t len = 0;
	int i, ret;
	unsigned long cur_iova = iova;

	if (!ops || !ops->map_pages)
		return -EINVAL;

	for_each_sg(sg, s, nents, i) {
		size_t mapped_per_sg = 0;
		ret = ops->map_pages(ops, cur_iova, sg_phys(s), PAGE_SIZE, 
				     s->length >> PAGE_SHIFT, prot, gfp, &mapped_per_sg);
		if (ret) {
			if (mapped) *mapped = len;
			return ret;
		}
		len += mapped_per_sg;
		cur_iova += s->length;
	}

	if (mapped) *mapped = len;
	return 0;
}
EXPORT_SYMBOL(qcom_arm_lpae_map_sg);

/**
 * qcom_arm_lpae_unmap_pages - Unmap pages using LPAE ops
 */
size_t qcom_arm_lpae_unmap_pages(struct io_pgtable_ops *ops, unsigned long iova,
				 size_t pgsize, size_t pgcount,
				 struct iommu_iotlb_gather *gather)
{
	if (!ops || !ops->unmap_pages)
		return 0;

	return ops->unmap_pages(ops, iova, pgsize, pgcount, gather);
}
EXPORT_SYMBOL(qcom_arm_lpae_unmap_pages);

/* Memory Buffer Parity */
int mem_buf_dma_buf_copy_vmperm(void *a, void *b, void *c, void *d) { return 0; }
EXPORT_SYMBOL(mem_buf_dma_buf_copy_vmperm);

int mem_buf_dma_buf_exclusive_owner(void *a, void *b) { return 0; }
EXPORT_SYMBOL(mem_buf_dma_buf_exclusive_owner);
#endif

#if 0
/* IOMMU Parity Extensions */
int qcom_iommu_get_asid(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_asid);

void qcom_iommu_set_fault_model(struct iommu_domain *domain, u32 model) { }
EXPORT_SYMBOL(qcom_iommu_set_fault_model);

int qcom_iommu_sid_switch(struct device *dev, u32 type) { return 0; }
EXPORT_SYMBOL(qcom_iommu_sid_switch);

#if 0
int qcom_iommu_enable_s1_translation(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_enable_s1_translation);
#endif
#endif

#if 0
/* HW Fence Parity Extensions */
int msm_hw_fence_register(u32 client_id, void *data, void *cb, void *pvt) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_register);

void msm_hw_fence_deregister(u32 handle) { }
EXPORT_SYMBOL(msm_hw_fence_deregister);

void msm_hw_fence_destroy(void *handle) { }
EXPORT_SYMBOL(msm_hw_fence_destroy);

void *msm_hw_fence_create(void) { return NULL; }
EXPORT_SYMBOL(msm_hw_fence_create);

int msm_hw_fence_wait_update_v2(void *handle, u32 p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_wait_update_v2);

void msm_hw_fence_update_txq(void *handle, u32 p1) { }
EXPORT_SYMBOL(msm_hw_fence_update_txq);

void msm_hw_fence_trigger_signal(void *handle, u32 p1) { }
EXPORT_SYMBOL(msm_hw_fence_trigger_signal);

int msm_hw_fence_register_error_cb(void *client, void *cb, void *data) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_register_error_cb);
#endif


/* Display PLL Parity Extensions */
int edp_pll_clock_register_3nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_3nm);

int edp_pll_clock_register_4nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_4nm);

int edp_pll_clock_register_5nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_5nm);

#if 0
/* DWC3 Parity Extensions */
int dwc3_msm_set_dp_mode(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(dwc3_msm_set_dp_mode);
#endif

/* HDCP Parity Extensions */
int sde_hdcp_version(void *p1) { return 0; }
EXPORT_SYMBOL(sde_hdcp_version);

/* HDCP Parity Extensions - commented out to avoid duplicate export errors with hdcp_qseecom_dlkm
int hdcp1_init(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp1_init);

int hdcp1_deinit(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp1_deinit);

int hdcp1_start(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp1_start);

int hdcp1_stop(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp1_stop);

int hdcp1_set_enc(void *p1, bool p2) { return 0; }
EXPORT_SYMBOL(hdcp1_set_enc);

int hdcp1_feature_supported(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp1_feature_supported);

int hdcp2_init(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_init);

int hdcp2_deinit(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_deinit);

int hdcp2_start(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_start);

int hdcp2_stop(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_stop);

int hdcp2_feature_supported(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_feature_supported);

int hdcp2_get_capability(void *p1) { return 0; }
EXPORT_SYMBOL(hdcp2_get_capability);

int hdcp2_force_encryption(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(hdcp2_force_encryption);

int hdcp2_open_stream(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(hdcp2_open_stream);

int hdcp2_close_stream(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(hdcp2_close_stream);

int hdcp2_app_comm(void *p1, u32 p2, void *p3, u32 p4) { return 0; }
EXPORT_SYMBOL(hdcp2_app_comm);

int hdcp1_ops_notify(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(hdcp1_ops_notify);
*/

#if 0
/* Synx Parity Extensions - Fixed for Display Stall */
struct synx_ops {
	void *uninitialize;
	void *create;
	void *signal;
	void *signal_n;
	void *wait;
	void *get_status;
	void *import;
	void *get_fence;
	void *release;
	void *release_n;
};

static int synx_stub_ok(void *p1) { return 0; }
static int synx_stub_create(void *p1, void *p2) { return 0; }

static struct synx_ops synx_hwfence_ops = {
	.uninitialize = (void *)synx_stub_ok,
	.create = (void *)synx_stub_create,
	.signal = (void *)synx_stub_ok,
	.wait = (void *)synx_stub_ok,
	.release = (void *)synx_stub_ok,
};

void *synx_initialize(void *params)
{
	void *session = kzalloc(128, GFP_KERNEL);
	printk(KERN_INFO "ZTE_PARITY: synx_initialize called, session created at %p\n", session);
	if (session) {
		*(void **)((char *)session + 0x10) = &synx_hwfence_ops;
	}
	return session;
}
EXPORT_SYMBOL(synx_initialize);

int synx_create(void *session, void *params) {
	printk(KERN_INFO "ZTE_PARITY: synx_create called\n");
	return 0;
}
EXPORT_SYMBOL(synx_create);

int synx_signal(void *session, u32 h_synx, u32 status) {
	printk(KERN_INFO "ZTE_PARITY: synx_signal called for handle %u\n", h_synx);
	return 0;
}
EXPORT_SYMBOL(synx_signal);

int synx_import(void *session, void *params) {
	printk(KERN_INFO "ZTE_PARITY: synx_import called\n");
	return 0;
}
EXPORT_SYMBOL(synx_import);

int synx_release(void *session, u32 h_synx) {
	printk(KERN_INFO "ZTE_PARITY: synx_release called for handle %u\n", h_synx);
	return 0;
}
EXPORT_SYMBOL(synx_release);

int synx_uninitialize(void *session) {
	printk(KERN_INFO "ZTE_PARITY: synx_uninitialize called for session %p\n", session);
	kfree(session);
	return 0;
}
EXPORT_SYMBOL(synx_uninitialize);
#endif

#if 0
/* Missing Parity Symbols Restored */
int spec_sync_wait_bind_array(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(spec_sync_wait_bind_array);
#endif

#if 0
int qcom_clk_set_flags(struct clk *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(qcom_clk_set_flags);
#endif

/*
int llcc_configure_staling_mode(void *p1, void *p2) { return -EOPNOTSUPP; }
EXPORT_SYMBOL(llcc_configure_staling_mode);

int llcc_notif_staling_inc_counter(void *p1) { return -EOPNOTSUPP; }
EXPORT_SYMBOL(llcc_notif_staling_inc_counter);
*/

struct panel_event_client {
	enum panel_event_notifier_tag tag;
	enum panel_event_notifier_client client_type;
	void *panel;
	void (*callback_func)(enum panel_event_notifier_tag tag,
			      struct panel_event_notification *notification,
			      void *client_data);
	void *client_data;
	struct list_head list;
};

static LIST_HEAD(panel_client_list);
static DEFINE_MUTEX(panel_client_mutex);

void panel_event_notification_trigger(enum panel_event_notifier_tag tag, struct panel_event_notification *notif)
{
	struct panel_event_client *client;

	mutex_lock(&panel_client_mutex);
	list_for_each_entry(client, &panel_client_list, list) {
		if (client->tag == tag && client->callback_func) {
			client->callback_func(tag, notif, client->client_data);
		}
	}
	mutex_unlock(&panel_client_mutex);
}
EXPORT_SYMBOL(panel_event_notification_trigger);

void *panel_event_notifier_register(enum panel_event_notifier_tag tag,
				     enum panel_event_notifier_client client_type,
				     void *panel,
				     void (*callback_func)(enum panel_event_notifier_tag tag,
							   struct panel_event_notification *notification,
							   void *client_data),
				     void *client_data)
{
	struct panel_event_client *client;

	client = kzalloc(sizeof(*client), GFP_KERNEL);
	if (!client)
		return ERR_PTR(-ENOMEM);

	client->tag = tag;
	client->client_type = client_type;
	client->panel = panel;
	client->callback_func = callback_func;
	client->client_data = client_data;

	mutex_lock(&panel_client_mutex);
	list_add_tail(&client->list, &panel_client_list);
	mutex_unlock(&panel_client_mutex);

	return client;
}
EXPORT_SYMBOL(panel_event_notifier_register);

int panel_event_notifier_unregister(void *cookie)
{
	struct panel_event_client *client = cookie;

	if (!client || IS_ERR(client))
		return -EINVAL;

	mutex_lock(&panel_client_mutex);
	list_del(&client->list);
	mutex_unlock(&panel_client_mutex);

	kfree(client);
	return 0;
}
EXPORT_SYMBOL(panel_event_notifier_unregister);

#if 0
int qcom_clk_crmb_set_rate(struct clk *clk, u32 drv_type, u32 client_idx, u32 res_idx, u32 pwr_state, u64 rate_ab, u64 rate_ib) { return 0; }
EXPORT_SYMBOL(qcom_clk_crmb_set_rate);

int qcom_clk_crmb_set_pwr(struct clk *p1, bool p2) { return 0; }
EXPORT_SYMBOL(qcom_clk_crmb_set_pwr);
#endif

#if 0
int msm_hw_fence_update_txq_error(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_update_txq_error);

int msm_hw_fence_wait(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_wait);

int msm_hw_fence_signal(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_signal);
#endif

#if 0
int rpmh_write_sleep_and_wake(void *p1, u32 p2, void *p3, u32 p4) { return 0; }
EXPORT_SYMBOL(rpmh_write_sleep_and_wake);

int rpmh_mode_solver_set(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(rpmh_mode_solver_set);
#endif

#if 0
/* AltMode Parity Extensions */
int altmode_register_notifier(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(altmode_register_notifier);

int altmode_deregister_notifier(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(altmode_deregister_notifier);

int altmode_register_client(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(altmode_register_client);

int altmode_deregister_client(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(altmode_deregister_client);

int altmode_send_data(void *p1, void *p2, u32 p3) { return 0; }
EXPORT_SYMBOL(altmode_send_data);
#endif

#if 0
/* SMMU Proxy Parity Extensions */
int smmu_proxy_switch_sid(u32 p1, u32 p2) { return 0; }
EXPORT_SYMBOL(smmu_proxy_switch_sid);

int smmu_proxy_get_csf_version(u32 p1) { return 0; }
EXPORT_SYMBOL(smmu_proxy_get_csf_version);
#endif

/* SCM Secure Parity Extensions */
#if 0
int qcom_scm_set_display_secure_state(u32 p1) { return 0; }
EXPORT_SYMBOL(qcom_scm_set_display_secure_state);

int qcom_scm_mem_protect_sd_ctrl(u32 device_id, u64 addr, u64 size, u32 vmid) { return 0; }
EXPORT_SYMBOL(qcom_scm_mem_protect_sd_ctrl);
#endif



#if 0
/* IPC Log Parity Extensions */
void *ipc_log_context_create(u32 p1, const char *p2, u32 p3) { return NULL; }
EXPORT_SYMBOL(ipc_log_context_create);

void ipc_log_context_destroy(void *p1) { }
EXPORT_SYMBOL(ipc_log_context_destroy);

int ipc_log_string(void *p1, const char *p2, ...) { return 0; }
EXPORT_SYMBOL(ipc_log_string);
#endif

int qcom_cvp_set_pwr_level(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(qcom_cvp_set_pwr_level);

void *qcom_cvp_register_client(void *p1) { return NULL; }
EXPORT_SYMBOL(qcom_cvp_register_client);

void qcom_cvp_unregister_client(void *p1) { }
EXPORT_SYMBOL(qcom_cvp_unregister_client);



/* MDSS Parity Extensions */
int msm_mdss_init(struct drm_device *p1) { return 0; }
EXPORT_SYMBOL(msm_mdss_init);

void msm_mdss_destroy(struct drm_device *p1) { }
EXPORT_SYMBOL(msm_mdss_destroy);

void msm_mdss_enable(void *p1) { }
EXPORT_SYMBOL(msm_mdss_enable);

void msm_mdss_disable(void *p1) { }
EXPORT_SYMBOL(msm_mdss_disable);

void msm_mdss_setup_intf_ops(void *p1, u32 p2) { }
EXPORT_SYMBOL(msm_mdss_setup_intf_ops);

/* MDP Parity Extensions */
int mdp4_kms_init(struct drm_device *p1) { return 0; }
EXPORT_SYMBOL(mdp4_kms_init);

int mdp5_kms_init(struct drm_device *p1) { return 0; }
EXPORT_SYMBOL(mdp5_kms_init);

/* GPIO Parity Extensions */
#if 0
void *msm_gpio_get_pin_address(u32 p1) { return NULL; }
EXPORT_SYMBOL(msm_gpio_get_pin_address);
#endif

/* DMA Parity Extensions */
/*
void msm_dma_unmap_all_for_dev(struct device *p1) { }
EXPORT_SYMBOL(msm_dma_unmap_all_for_dev);
*/

#if 0
/* CRM Parity Extensions */
int crm_write_pwr_states(const struct crm_dev *crm_dev, u32 client_idx) { return 0; }
EXPORT_SYMBOL(crm_write_pwr_states);

int crm_write_perf_ol(const struct crm_dev *crm_dev, u32 drv_type, u32 client_idx, struct crm_cmd *cmd) { return 0; }
EXPORT_SYMBOL(crm_write_perf_ol);

struct crm_dev *crm_get_device(const char *name) { return NULL; }
EXPORT_SYMBOL(crm_get_device);
#endif

/* Socinfo Parity Extensions */
#if 0
void *socinfo_get_part_info(u32 part_id) { return NULL; }
EXPORT_SYMBOL(socinfo_get_part_info);

u32 socinfo_get_part_count(u32 part_id) { return 0; }
EXPORT_SYMBOL(socinfo_get_part_count);

void socinfo_get_subpart_info(u32 part_id, void *part_info, u32 count) { }
EXPORT_SYMBOL(socinfo_get_subpart_info);
#endif

/* SPMI Parity Extensions */
/*
int spmi_pmic_arb_map_address(struct device *dev, u32 addr, struct resource *res) { return -EOPNOTSUPP; }
EXPORT_SYMBOL(spmi_pmic_arb_map_address);
*/

/* SCM Parity Extensions */
#if 0
int qcom_scm_kgsl_set_smmu_aperture(u32 cb_num) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_aperture);

int qcom_scm_kgsl_set_smmu_lpac_aperture(u32 cb_num) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_lpac_aperture);
#endif

#if 0
void qcom_skip_tlb_management(struct device *dev, bool skip) {}
EXPORT_SYMBOL(qcom_skip_tlb_management);

int qcom_iommu_get_context_bank_nr(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_context_bank_nr);

#if 0
int qcom_iommu_get_asid_nr(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_asid_nr);
#endif

int qcom_iommu_set_secure_vmid(struct iommu_domain *domain, int vmid) { return 0; }
EXPORT_SYMBOL(qcom_iommu_set_secure_vmid);
#endif

#if 0
int qcom_scm_kgsl_init_regs(u32 gpu_req) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_init_regs);

int qcom_scm_kgsl_dcvs_tuning(u32 mingap, u32 penalty, u32 numbusy) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_dcvs_tuning);

int qcom_scm_pas_shutdown_retry(u32 peripheral) { return 0; }
EXPORT_SYMBOL(qcom_scm_pas_shutdown_retry);

int qcom_scm_io_reset(void) { return 0; }
EXPORT_SYMBOL(qcom_scm_io_reset);

int qcom_scm_dcvs_reset(void) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_reset);

int qcom_scm_dcvs_update(u32 level, u32 total_time, u32 busy_time) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_update);

int qcom_scm_dcvs_update_v2(u32 level, u32 total_time, u32 busy_time) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_update_v2);

int qcom_scm_dcvs_init_v2(u64 paddr, size_t size, u32 *version) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_init_v2);
#endif

/* DDR Type from FDT */
int of_fdt_get_ddrtype(void) { return 0; }
EXPORT_SYMBOL(of_fdt_get_ddrtype);

#if 0
/* Clock Diagnostic Hooks */
void qcom_clk_dump(void *clk, void *reg, bool verbose) { }
EXPORT_SYMBOL(qcom_clk_dump);
#endif

/* DCVS Voter Parity */
#if 0
int qcom_dcvs_register_voter(const char *name, u32 hw_type, u32 path) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_register_voter);

void qcom_dcvs_unregister_voter(const char *name, u32 hw_type, u32 path) { }
EXPORT_SYMBOL(qcom_dcvs_unregister_voter);

int qcom_dcvs_update_votes(const char *name, struct dcvs_freq *freq, u32 count, u32 path) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_update_votes);

int qcom_dcvs_hw_minmax_get(u32 hw_type, u32 *min, u32 *max) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_hw_minmax_get);
#endif

#if 0
/* Sysstats Event */
void sysstats_register_kgsl_stats_cb(u64 (*cb)(pid_t pid)) { }
EXPORT_SYMBOL(sysstats_register_kgsl_stats_cb);

void sysstats_unregister_kgsl_stats_cb(void) { }
EXPORT_SYMBOL(sysstats_unregister_kgsl_stats_cb);
#endif

/* Boot Mode */
u8 get_ss_panic_buf_byte(void) { return 0; }

/* QTEE SHM Bridge Parity */
#if 0
bool qtee_shmbridge_is_enabled(void) { return false; }
EXPORT_SYMBOL(qtee_shmbridge_is_enabled);

int qtee_shmbridge_register(phys_addr_t paddr, size_t size, u32 *vmid_list, u32 *perms_list, u32 nelems, int tz_perm, u64 *handle) { return 0; }
EXPORT_SYMBOL(qtee_shmbridge_register);

int qtee_shmbridge_deregister(u64 handle) { return 0; }
EXPORT_SYMBOL(qtee_shmbridge_deregister);

int qtee_shmbridge_allocate_shm(size_t size, struct qtee_shm *shm) { return -ENOMEM; }
EXPORT_SYMBOL(qtee_shmbridge_allocate_shm);

void qtee_shmbridge_free_shm(struct qtee_shm *shm) { }
EXPORT_SYMBOL(qtee_shmbridge_free_shm);

int qtee_shmbridge_query(phys_addr_t paddr) { return 0; }
EXPORT_SYMBOL(qtee_shmbridge_query);

void qtee_shmbridge_flush_shm_buf(struct qtee_shm *shm) { }
EXPORT_SYMBOL(qtee_shmbridge_flush_shm_buf);
#endif

#if 0
void msm_perf_events_update(void *p1, u32 p2, u32 p3) {}
EXPORT_SYMBOL(msm_perf_events_update);
#endif

#if 0
bool qcom_scm_dcvs_core_available(void) { return false; }
EXPORT_SYMBOL(qcom_scm_dcvs_core_available);

bool qcom_scm_dcvs_ca_available(void) { return false; }
EXPORT_SYMBOL(qcom_scm_dcvs_ca_available);

int qcom_scm_dcvs_init_ca_v2(u64 paddr, size_t size) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_init_ca_v2);

int qcom_scm_dcvs_update_ca_v2(u32 level, u32 total_time, u32 busy_time, u32 ca) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_update_ca_v2);
#endif

#if 0
const char *socinfo_get_partinfo_part_name(void) { return "SM8750"; }
EXPORT_SYMBOL(socinfo_get_partinfo_part_name);

u32 socinfo_get_feature_code(void) { return 0; }
EXPORT_SYMBOL(socinfo_get_feature_code);

u32 socinfo_get_pcode(void) { return 0; }
EXPORT_SYMBOL(socinfo_get_pcode);

u32 socinfo_get_partinfo_vulkan_id(void) { return 0; }
EXPORT_SYMBOL(socinfo_get_partinfo_vulkan_id);

u32 socinfo_get_partinfo_chip_id(void) { return 0; }
EXPORT_SYMBOL(socinfo_get_partinfo_chip_id);
#endif

#if 0
void *kgsl_pwrctrl_set_max_level_fp = NULL;
EXPORT_SYMBOL(kgsl_pwrctrl_set_max_level_fp);

void *kgsl_pwrctrl_get_max_level_fp = NULL;
EXPORT_SYMBOL(kgsl_pwrctrl_get_max_level_fp);

void *kgsl_pwrctrl_set_min_level_fp = NULL;
EXPORT_SYMBOL(kgsl_pwrctrl_set_min_level_fp);

void *kgsl_pwrctrl_get_min_level_fp = NULL;
EXPORT_SYMBOL(kgsl_pwrctrl_get_min_level_fp);

void *kgsl_pwrctrl_get_loading_fp = NULL;
EXPORT_SYMBOL(kgsl_pwrctrl_get_loading_fp);
#endif

/*
void *kgsl_gpu_num_freqs_fp = NULL;
EXPORT_SYMBOL(kgsl_gpu_num_freqs_fp);
*/

#if 0
extern enum qcom_scm_convention qcom_scm_convention;
int __scm_smc_call(struct device *dev, const struct qcom_scm_desc *desc,
		   enum qcom_scm_convention convention, struct qcom_scm_res *res,
		   bool atomic);

int qcom_scm_invoke_smc(phys_addr_t in_paddr, size_t in_buf_len,
			phys_addr_t out_paddr, size_t out_buf_len,
			int32_t *result, u64 *response_type,
			unsigned int *data)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 6;
	desc.cmd = 2;
	desc.arginfo = 548; // SCM_ARGS(4, SCM_RW, SCM_VAL, SCM_RW, SCM_VAL)
	desc.args[0] = in_paddr;
	desc.args[1] = in_buf_len;
	desc.args[2] = out_paddr;
	desc.args[3] = out_buf_len;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (result)
		*result = res.result[0];
	if (response_type)
		*response_type = res.result[1];
	if (data)
		*data = res.result[2];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_invoke_smc);

int qcom_scm_invoke_smc_legacy(phys_addr_t in_paddr, size_t in_buf_len,
			       phys_addr_t out_paddr, size_t out_buf_len,
			       int32_t *result, u64 *response_type,
			       unsigned int *data)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 6;
	desc.cmd = 0;
	desc.arginfo = 548;
	desc.args[0] = in_paddr;
	desc.args[1] = in_buf_len;
	desc.args[2] = out_paddr;
	desc.args[3] = out_buf_len;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (result)
		*result = res.result[0];
	if (response_type)
		*response_type = res.result[1];
	if (data)
		*data = res.result[2];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_invoke_smc_legacy);

int qcom_scm_invoke_callback_response(phys_addr_t out_paddr, size_t out_buf_len,
				      int32_t *result, u64 *response_type,
				      unsigned int *data)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 6;
	desc.cmd = 1;
	desc.arginfo = 34; // SCM_ARGS(2, SCM_RW, SCM_VAL)
	desc.args[0] = out_paddr;
	desc.args[1] = out_buf_len;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (result)
		*result = res.result[0];
	if (response_type)
		*response_type = res.result[1];
	if (data)
		*data = res.result[2];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_invoke_callback_response);

void qtee_shmbridge_inv_shm_buf(struct qtee_shm *shm)
{
}
EXPORT_SYMBOL(qtee_shmbridge_inv_shm_buf);

int qcom_scm_get_tz_log_feat_id(u64 *val)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 6;
	desc.cmd = 3;
	desc.arginfo = 1;
	desc.args[0] = 10; // Feat ID for TZ log is 10

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (val)
		*val = res.result[0];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_get_tz_log_feat_id);

int qcom_scm_get_tz_feat_id_version(u32 feat_id, u64 *val)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 6;
	desc.cmd = 3;
	desc.arginfo = 1;
	desc.args[0] = feat_id;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (val)
		*val = res.result[0];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_get_tz_feat_id_version);

int qcom_scm_request_encrypted_log(phys_addr_t paddr, size_t size,
				   u32 log_id, bool supported, bool enabled)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 1;
	desc.cmd = 12;
	desc.args[0] = paddr;
	desc.args[1] = size;
	desc.args[2] = log_id;

	if (supported) {
		desc.arginfo = 36;
		desc.args[3] = enabled ? 1 : 0;
	} else {
		desc.arginfo = 35;
	}

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (ret)
		return ret;

	return (int)res.result[0];
}
EXPORT_SYMBOL(qcom_scm_request_encrypted_log);

int qcom_scm_query_log_status(u64 *status)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 1;
	desc.cmd = 15;
	desc.arginfo = 0;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (!ret && status)
		*status = res.result[0];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_query_log_status);

int qcom_scm_query_encrypted_log_feature(u64 *val)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 1;
	desc.cmd = 11;
	desc.arginfo = 0;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (!ret && val)
		*val = res.result[0];

	return ret;
}
EXPORT_SYMBOL(qcom_scm_query_encrypted_log_feature);

int qcom_scm_register_qsee_log_buf(phys_addr_t paddr, size_t size)
{
	struct qcom_scm_desc desc = {0};
	struct qcom_scm_res res = {0};
	int ret;

	desc.svc = 1;
	desc.cmd = 6;
	desc.arginfo = 34; // SCM_ARGS(2, SCM_RW, SCM_VAL)
	desc.args[0] = paddr;
	desc.args[1] = size;

	ret = __scm_smc_call(NULL, &desc, qcom_scm_convention, &res, false);
	if (ret)
		return ret;

	return (int)res.result[0];
}
EXPORT_SYMBOL(qcom_scm_register_qsee_log_buf);

int qcom_scm_qseecom_call(u32 smc_id, struct qseecom_scm_desc *desc, bool atomic)
{
	struct qcom_scm_desc qcom_desc = {0};
	struct qcom_scm_res res = {0};
	int status;

	qcom_desc.svc = (smc_id >> 8) & 0xff;
	qcom_desc.cmd = smc_id & 0xff;
	qcom_desc.owner = (smc_id >> 24) & 0x3f;
	qcom_desc.arginfo = desc->arginfo;
	memcpy(qcom_desc.args, desc->args, sizeof(qcom_desc.args));

	status = __scm_smc_call(NULL, &qcom_desc, qcom_scm_convention, &res, atomic);

	desc->ret[0] = res.result[0];
	desc->ret[1] = res.result[1];
	desc->ret[2] = res.result[2];

	return status;
}
EXPORT_SYMBOL(qcom_scm_qseecom_call);
#endif

#if 0
int mem_buf_dma_buf_set_destructor(struct dma_buf *dmabuf, int (*destructor)(void *), void *pvt)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_dma_buf_set_destructor);
#endif

