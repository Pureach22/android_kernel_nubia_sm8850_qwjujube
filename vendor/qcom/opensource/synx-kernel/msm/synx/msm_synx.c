/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/dma-fence.h>
#include <linux/sync_file.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/list.h>
#include <linux/workqueue.h>
#include <linux/pm.h>
#include <linux/suspend.h>
#include <linux/notifier.h>

#include <synx_api.h>
#include <synx_interop.h>

/* Global debugging options */
int synx_debug = 0;
EXPORT_SYMBOL(synx_debug);

int synx_columns = 0;
EXPORT_SYMBOL(synx_columns);


struct msm_synx_object {
	u32 handle;
	char name[64];
	struct dma_fence *fence;
	enum synx_signal_status status;
	spinlock_t lock;
	struct list_head cb_list;
	struct list_head list;
	bool active;
};

struct msm_synx_callback {
	struct list_head list;
	u32 h_synx;
	synx_callback_fn cb_func;
	void *userdata;
};

struct msm_synx_fence {
	struct dma_fence base;
	u32 handle;
};

/* Lock and global list tracking active synx objects */
static DEFINE_SPINLOCK(synx_lock);
static LIST_HEAD(synx_objects);
static u32 next_handle = 1;

/* Declarations of external dependencies */
extern void *qcom_register_ssr_notifier(const char *name, struct notifier_block *nb);
extern int qcom_unregister_ssr_notifier(void *handle, struct notifier_block *nb);
extern int ipclite_register_client(int (*cb)(void *payload, int size), u32 id);

/* DMA Fence operations implementation for synx-created fences */
static const char *msm_synx_fence_get_driver_name(struct dma_fence *fence)
{
	return "msm_synx";
}

static const char *msm_synx_fence_get_timeline_name(struct dma_fence *fence)
{
	return "synx_timeline";
}

static const struct dma_fence_ops msm_synx_fence_ops = {
	.get_driver_name = msm_synx_fence_get_driver_name,
	.get_timeline_name = msm_synx_fence_get_timeline_name,
};

static struct dma_fence *msm_synx_create_dma_fence(u32 handle)
{
	struct msm_synx_fence *synx_fence;
	static u64 fence_context = 0;
	static atomic_t seqno = ATOMIC_INIT(0);
	static DEFINE_SPINLOCK(fence_lock);

	if (fence_context == 0)
		fence_context = dma_fence_context_alloc(1);

	synx_fence = kzalloc(sizeof(*synx_fence), GFP_KERNEL);
	if (!synx_fence)
		return NULL;

	synx_fence->handle = handle;
	dma_fence_init(&synx_fence->base, &msm_synx_fence_ops, &fence_lock,
		       fence_context, atomic_inc_return(&seqno));

	return &synx_fence->base;
}

/* Core Synx API Functions */
struct synx_session *synx_initialize(struct synx_initialization_params *params)
{
	struct synx_session *session;

	session = kzalloc(sizeof(*session), GFP_KERNEL);
	if (!session)
		return ERR_PTR(-ENOMEM);

	session->client_id = params ? params->id : SYNX_CLIENT_NATIVE;
	session->active = true;

	if (params && params->name)
		strscpy(session->name, params->name, sizeof(session->name));

	if (params && params->ptr) {
		void *vaddr = (void *)get_zeroed_page(GFP_KERNEL);
		if (vaddr) {
			params->ptr->vaddr = vaddr;
			params->ptr->dev_addr = virt_to_phys(vaddr);
			params->ptr->size = PAGE_SIZE;
			session->queue = *params->ptr;
		}
	}

	return session;
}
EXPORT_SYMBOL(synx_initialize);

int synx_uninitialize(struct synx_session *session)
{
	if (!session)
		return -EINVAL;

	if (session->queue.vaddr) {
		free_page((unsigned long)session->queue.vaddr);
	}

	kfree(session);
	return 0;
}
EXPORT_SYMBOL(synx_uninitialize);

int synx_create(struct synx_session *session, struct synx_create_params *params)
{
	struct msm_synx_object *obj;
	unsigned long flags;

	if (!session || !params || !params->h_synx)
		return -EINVAL;

	obj = kzalloc(sizeof(*obj), GFP_KERNEL);
	if (!obj)
		return -ENOMEM;

	spin_lock_init(&obj->lock);
	INIT_LIST_HEAD(&obj->cb_list);
	obj->status = SYNX_STATE_ACTIVE;
	obj->active = true;

	if (params->name)
		strscpy(obj->name, params->name, sizeof(obj->name));

	spin_lock_irqsave(&synx_lock, flags);
	obj->handle = next_handle++;
	list_add_tail(&obj->list, &synx_objects);
	spin_unlock_irqrestore(&synx_lock, flags);

	if (params->fence) {
		obj->fence = dma_fence_get(params->fence);
	} else {
		obj->fence = msm_synx_create_dma_fence(obj->handle);
	}

	*params->h_synx = obj->handle;
	return 0;
}
EXPORT_SYMBOL(synx_create);

int synx_release(struct synx_session *session, u32 h_synx)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct msm_synx_callback *cb, *cb_tmp;
	unsigned long flags;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == h_synx && tmp->active) {
			obj = tmp;
			list_del(&obj->list);
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	spin_lock_irqsave(&obj->lock, flags);
	obj->active = false;
	list_for_each_entry_safe(cb, cb_tmp, &obj->cb_list, list) {
		list_del(&cb->list);
		kfree(cb);
	}
	spin_unlock_irqrestore(&obj->lock, flags);

	if (obj->fence) {
		dma_fence_put(obj->fence);
	}

	kfree(obj);
	return 0;
}
EXPORT_SYMBOL(synx_release);

int synx_release_n(struct synx_session *session, u32 *h_synx, u32 count)
{
	u32 i;
	if (!h_synx)
		return -EINVAL;
	for (i = 0; i < count; i++) {
		synx_release(session, h_synx[i]);
	}
	return 0;
}
EXPORT_SYMBOL(synx_release_n);

int synx_signal(struct synx_session *session, u32 h_synx, u32 status)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct msm_synx_callback *cb, *cb_tmp;
	LIST_HEAD(local_cb_list);
	unsigned long flags;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == h_synx && tmp->active) {
			obj = tmp;
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	spin_lock_irqsave(&obj->lock, flags);
	if (obj->status != SYNX_STATE_ACTIVE) {
		spin_unlock_irqrestore(&obj->lock, flags);
		return -EALREADY;
	}
	obj->status = status;
	list_replace_init(&obj->cb_list, &local_cb_list);
	spin_unlock_irqrestore(&obj->lock, flags);

	if (obj->fence) {
		dma_fence_signal(obj->fence);
	}

	list_for_each_entry_safe(cb, cb_tmp, &local_cb_list, list) {
		if (cb->cb_func)
			cb->cb_func(h_synx, status, cb->userdata);
		list_del(&cb->list);
		kfree(cb);
	}

	return 0;
}
EXPORT_SYMBOL(synx_signal);

int synx_async_wait(struct synx_session *session, struct synx_callback_params *params)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct msm_synx_callback *cb;
	unsigned long flags;
	u32 status;

	if (!params || !params->cb_func)
		return -EINVAL;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == params->h_synx && tmp->active) {
			obj = tmp;
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	spin_lock_irqsave(&obj->lock, flags);
	status = obj->status;
	if (status != SYNX_STATE_ACTIVE) {
		spin_unlock_irqrestore(&obj->lock, flags);
		params->cb_func(params->h_synx, status, params->userdata);
		return 0;
	}

	cb = kzalloc(sizeof(*cb), GFP_ATOMIC);
	if (!cb) {
		spin_unlock_irqrestore(&obj->lock, flags);
		return -ENOMEM;
	}

	cb->h_synx = params->h_synx;
	cb->cb_func = params->cb_func;
	cb->userdata = params->userdata;
	list_add_tail(&cb->list, &obj->cb_list);
	spin_unlock_irqrestore(&obj->lock, flags);

	return 0;
}
EXPORT_SYMBOL(synx_async_wait);

int synx_cancel_async_wait(struct synx_session *session, struct synx_callback_params *params)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct msm_synx_callback *cb, *cb_tmp;
	unsigned long flags;
	bool found = false;

	if (!params)
		return -EINVAL;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == params->h_synx && tmp->active) {
			obj = tmp;
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	spin_lock_irqsave(&obj->lock, flags);
	list_for_each_entry_safe(cb, cb_tmp, &obj->cb_list, list) {
		if (cb->cb_func == params->cb_func && cb->userdata == params->userdata) {
			list_del(&cb->list);
			kfree(cb);
			found = true;
			break;
		}
	}
	spin_unlock_irqrestore(&obj->lock, flags);

	return found ? 0 : -ENOENT;
}
EXPORT_SYMBOL(synx_cancel_async_wait);

int synx_wait(struct synx_session *session, u32 h_synx, u32 timeout_ms)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct dma_fence *fence = NULL;
	unsigned long flags;
	long ret;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == h_synx && tmp->active) {
			obj = tmp;
			fence = obj->fence;
			if (fence)
				dma_fence_get(fence);
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	if (!fence)
		return 0;

	if (timeout_ms == SYNX_NO_TIMEOUT) {
		ret = dma_fence_wait(fence, true);
	} else {
		ret = dma_fence_wait_timeout(fence, true, msecs_to_jiffies(timeout_ms));
	}

	dma_fence_put(fence);

	if (ret < 0)
		return ret;
	if (ret == 0)
		return -ETIMEDOUT;

	return 0;
}
EXPORT_SYMBOL(synx_wait);

int synx_get_status(struct synx_session *session, u32 h_synx, u32 *status)
{
	struct msm_synx_object *obj = NULL, *tmp;
	unsigned long flags;

	if (!status)
		return -EINVAL;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == h_synx && tmp->active) {
			obj = tmp;
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	if (!obj)
		return -EINVAL;

	spin_lock_irqsave(&obj->lock, flags);
	*status = obj->status;
	spin_unlock_irqrestore(&obj->lock, flags);

	return 0;
}
EXPORT_SYMBOL(synx_get_status);

int synx_import(struct synx_session *session, struct synx_import_params *params)
{
	struct msm_synx_object *obj;
	unsigned long flags;

	if (!session || !params || !params->indv.new_h_synx)
		return -EINVAL;

	obj = kzalloc(sizeof(*obj), GFP_KERNEL);
	if (!obj)
		return -ENOMEM;

	spin_lock_init(&obj->lock);
	INIT_LIST_HEAD(&obj->cb_list);
	obj->status = SYNX_STATE_ACTIVE;
	obj->active = true;
	strscpy(obj->name, "imported_fence", sizeof(obj->name));

	spin_lock_irqsave(&synx_lock, flags);
	obj->handle = next_handle++;
	list_add_tail(&obj->list, &synx_objects);
	spin_unlock_irqrestore(&synx_lock, flags);

	if (params->indv.fence) {
		obj->fence = dma_fence_get((struct dma_fence *)params->indv.fence);
	} else {
		obj->fence = msm_synx_create_dma_fence(obj->handle);
	}

	*params->indv.new_h_synx = obj->handle;
	return 0;
}
EXPORT_SYMBOL(synx_import);

void *synx_get_fence(struct synx_session *session, u32 h_synx)
{
	struct msm_synx_object *obj = NULL, *tmp;
	struct dma_fence *fence = NULL;
	unsigned long flags;

	spin_lock_irqsave(&synx_lock, flags);
	list_for_each_entry(tmp, &synx_objects, list) {
		if (tmp->handle == h_synx && tmp->active) {
			obj = tmp;
			fence = obj->fence;
			if (fence)
				dma_fence_get(fence);
			break;
		}
	}
	spin_unlock_irqrestore(&synx_lock, flags);

	return fence;
}
EXPORT_SYMBOL(synx_get_fence);

int synx_merge(struct synx_session *session, u32 *h_synx, u32 count, u32 *h_merged)
{
	struct synx_create_params create_params;
	u32 merged_h = 0;
	int ret;

	if (!session || !h_synx || count == 0 || !h_merged)
		return -EINVAL;

	memset(&create_params, 0, sizeof(create_params));
	create_params.name = "merged_synx";
	create_params.h_synx = &merged_h;

	ret = synx_create(session, &create_params);
	if (ret)
		return ret;

	*h_merged = merged_h;
	return 0;
}
EXPORT_SYMBOL(synx_merge);

int synx_recover(enum synx_client_id id)
{
	return 0;
}
EXPORT_SYMBOL(synx_recover);

int synx_enable_resources(enum synx_client_id id, enum synx_resource_id res, bool pwr_on)
{
	return 0;
}
EXPORT_SYMBOL(synx_enable_resources);

int synx_bind(u32 h_synx, u64 device_addr, u32 size)
{
	return 0;
}
EXPORT_SYMBOL(synx_bind);

int synx_register_ops(void *ops)
{
	return 0;
}
EXPORT_SYMBOL(synx_register_ops);

int synx_deregister_ops(void *ops)
{
	return 0;
}
EXPORT_SYMBOL(synx_deregister_ops);

int synx_ipc_callback(void *payload, int size)
{
	return 0;
}
EXPORT_SYMBOL(synx_ipc_callback);

int synx_external_callback(void *payload, int size)
{
	return 0;
}
EXPORT_SYMBOL(synx_external_callback);

void synx_fence_release(struct dma_fence *fence)
{
}
EXPORT_SYMBOL(synx_fence_release);

void synx_fence_callback(struct dma_fence *fence, struct dma_fence_cb *cb)
{
}
EXPORT_SYMBOL(synx_fence_callback);

/* Character device interface file operations */
struct synx_ioctl_create {
	char name[64];
	u32 flags;
	u32 h_synx;
	u64 fence;
	s32 fd;
};

struct synx_ioctl_import {
	u32 flags;
	u32 h_synx;
	u32 new_h_synx;
	u32 padding;
	u64 fence;
	s32 fd;
	u32 padding2;
};

#define SYNX_IOC_MAGIC 'S'
#define SYNX_IOC_COMMON _IOWR(SYNX_IOC_MAGIC, 0x82, struct synx_ioctl_ops)

struct synx_ioctl_ops {
	u32 op_id;
	u32 size;
	u32 reserved;
	u32 padding;
	u64 user_payload;
};

static int synx_open(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}

static int synx_close(struct inode *inode, struct file *file)
{
	struct synx_session *session = file->private_data;
	if (session) {
		synx_uninitialize(session);
		file->private_data = NULL;
	}
	return 0;
}

static long synx_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct synx_ioctl_ops ops;
	struct synx_session *session = file->private_data;
	int ret = -EINVAL;

	if (cmd != SYNX_IOC_COMMON)
		return -ENOTTY;

	if (copy_from_user(&ops, (void __user *)arg, sizeof(ops)))
		return -EFAULT;

	if (!session && ops.op_id != 14 && ops.op_id != 17)
		return -EINVAL;

	switch (ops.op_id) {
	case 14: /* initialize */
	case 17: /* initialize_v3 */
		{
			struct synx_initialization_params params;
			struct synx_queue_desc q_desc;
			char name[64] = {0};
			u64 q_desc_ptr = 0;
			u32 flags = 0;

			if (ops.op_id == 14) {
				struct {
					char name[64];
					u64 q_desc_user_ptr;
					u32 flags;
				} init_payload;

				if (copy_from_user(&init_payload, (void __user *)ops.user_payload, 76))
					return -EFAULT;

				memcpy(name, init_payload.name, 64);
				q_desc_ptr = init_payload.q_desc_user_ptr;
				flags = init_payload.flags;
			} else {
				struct {
					char name[64];
					u64 q_desc_user_ptr;
					u32 flags;
					u32 reserved[10];
				} init_v3_payload;

				if (copy_from_user(&init_v3_payload, (void __user *)ops.user_payload, 112))
					return -EFAULT;

				memcpy(name, init_v3_payload.name, 64);
				q_desc_ptr = init_v3_payload.q_desc_user_ptr;
				flags = init_v3_payload.flags;
			}

			memset(&params, 0, sizeof(params));
			params.name = name;
			params.id = (enum synx_client_id)flags;
			if (q_desc_ptr) {
				memset(&q_desc, 0, sizeof(q_desc));
				params.ptr = &q_desc;
			}

			session = synx_initialize(&params);
			if (IS_ERR(session))
				return PTR_ERR(session);

			file->private_data = session;

			if (q_desc_ptr) {
				if (copy_to_user((void __user *)q_desc_ptr, &q_desc, sizeof(q_desc)))
					return -EFAULT;
			}

			if (ops.op_id == 17) {
				u64 dev_addr = q_desc.dev_addr;
				u32 size = q_desc.size;
				u64 vaddr = (u64)q_desc.vaddr;

				if (copy_to_user((void __user *)(ops.user_payload + 80), &dev_addr, 8) ||
				    copy_to_user((void __user *)(ops.user_payload + 88), &size, 4) ||
				    copy_to_user((void __user *)(ops.user_payload + 96), &vaddr, 8))
					return -EFAULT;
			}

			ret = 0;
		}
		break;

	case 0: /* create */
		{
			struct synx_ioctl_create payload;
			struct synx_create_params params;
			u32 h_synx = 0;

			if (copy_from_user(&payload, (void __user *)ops.user_payload, sizeof(payload)))
				return -EFAULT;

			memset(&params, 0, sizeof(params));
			params.name = payload.name;
			params.flags = payload.flags;
			params.h_synx = &h_synx;

			if (payload.fd >= 0) {
				params.fence = sync_file_get_fence(payload.fd);
			}

			ret = synx_create(session, &params);
			if (params.fence)
				dma_fence_put(params.fence);

			if (ret == 0) {
				payload.h_synx = h_synx;
				if (copy_to_user((void __user *)ops.user_payload, &payload, sizeof(payload)))
					return -EFAULT;
			}
		}
		break;

	case 1: /* release */
		{
			u32 h_synx = 0;
			if (get_user(h_synx, (u32 __user *)(ops.user_payload + 64)))
				return -EFAULT;

			ret = synx_release(session, h_synx);
		}
		break;

	case 2: /* signal */
		{
			u32 h_synx = 0, status = 0;
			if (get_user(h_synx, (u32 __user *)ops.user_payload) ||
			    get_user(status, (u32 __user *)(ops.user_payload + 4)))
				return -EFAULT;

			ret = synx_signal(session, h_synx, status);
		}
		break;

	case 6: /* wait */
		{
			u32 h_synx = 0;
			u64 timeout_ms = 0;

			if (get_user(h_synx, (u32 __user *)ops.user_payload) ||
			    get_user(timeout_ms, (u64 __user *)(ops.user_payload + 8)))
				return -EFAULT;

			ret = synx_wait(session, h_synx, (u32)timeout_ms);

			ops.reserved = ret;
			if (copy_to_user((void __user *)arg, &ops, sizeof(ops)))
				return -EFAULT;

			ret = 0;
		}
		break;

	case 10: /* import */
		{
			struct synx_ioctl_import payload;
			struct synx_import_params params;
			u32 new_h_synx = 0;

			if (copy_from_user(&payload, (void __user *)ops.user_payload, sizeof(payload)))
				return -EFAULT;

			memset(&params, 0, sizeof(params));
			params.type = payload.flags;
			params.indv.flags = payload.flags;
			params.indv.new_h_synx = &new_h_synx;

			if (payload.fd >= 0) {
				params.indv.fence = sync_file_get_fence(payload.fd);
			}

			ret = synx_import(session, &params);
			if (params.indv.fence)
				dma_fence_put((struct dma_fence *)params.indv.fence);

			if (ret == 0) {
				payload.new_h_synx = new_h_synx;
				if (copy_to_user((void __user *)ops.user_payload, &payload, sizeof(payload)))
					return -EFAULT;
			}
		}
		break;

	default:
		pr_debug("synx: unsupported op_id %d\n", ops.op_id);
		break;
	}

	return ret;
}

static const struct file_operations synx_fops = {
	.owner = THIS_MODULE,
	.open = synx_open,
	.release = synx_close,
	.unlocked_ioctl = synx_ioctl,
	.compat_ioctl = synx_ioctl,
};

/* Module Initialization and Interops Registration */
static struct class *synx_class;
static dev_t synx_dev;
static struct cdev synx_cdev;

static struct synx_hwfence_interops my_hwfence_ops;

static int my_synx_share_handle_status(struct synx_import_indv_params *params, u64 handle, u32 *signal_status)
{
	if (signal_status)
		*signal_status = SYNX_STATE_ACTIVE;
	return 0;
}

static void *my_synx_get_fence(u32 h_synx)
{
	return synx_get_fence(NULL, h_synx);
}

static int my_synx_notify_recover(enum synx_core_id id)
{
	return 0;
}

static int my_synx_signal_fence(enum synx_core_id id, bool is_ssr, u32 h_synx, u32 status)
{
	return synx_signal(NULL, h_synx, status);
}

static int my_synx_dma_add_cb_no_enable_sig(struct dma_fence *fence, struct dma_fence_cb *cb, dma_fence_func_t func)
{
	return dma_fence_add_callback(fence, cb, func);
}

static struct synx_hwfence_interops my_synx_ops = {
	.share_handle_status = my_synx_share_handle_status,
	.get_fence = my_synx_get_fence,
	.notify_recover = my_synx_notify_recover,
	.signal_fence = my_synx_signal_fence,
	.dma_add_cb_no_enable_sig = my_synx_dma_add_cb_no_enable_sig,
};

static int synx_pm_callback(struct notifier_block *nb, unsigned long action, void *data)
{
	return NOTIFY_OK;
}
static struct notifier_block qcom_synx_notif_block = {
	.notifier_call = synx_pm_callback,
};

static int synx_cdsp_restart_notifier(struct notifier_block *nb, unsigned long action, void *data)
{
	return NOTIFY_OK;
}
static struct notifier_block ssr_nb = {
	.notifier_call = synx_cdsp_restart_notifier,
};

static int __init msm_synx_init(void)
{
	int ret;
	struct device *dev;

	ret = alloc_chrdev_region(&synx_dev, 0, 1, "synx_device");
	if (ret)
		return ret;

	cdev_init(&synx_cdev, &synx_fops);
	synx_cdev.owner = THIS_MODULE;
	ret = cdev_add(&synx_cdev, synx_dev, 1);
	if (ret)
		goto unreg_chrdev;

	synx_class = class_create("SYNX_DEVICE_NAME");
	if (IS_ERR(synx_class)) {
		ret = PTR_ERR(synx_class);
		goto del_cdev;
	}

	dev = device_create(synx_class, NULL, synx_dev, NULL, "synx_device");
	if (IS_ERR(dev)) {
		ret = PTR_ERR(dev);
		goto destroy_class;
	}

	register_pm_notifier(&qcom_synx_notif_block);
	qcom_register_ssr_notifier("cdsp", &ssr_nb);
	ipclite_register_client(synx_ipc_callback, 0);
	synx_hwfence_init_interops(&my_synx_ops, &my_hwfence_ops);

	pr_info("msm_synx: driver initialized successfully\n");
	return 0;

destroy_class:
	class_destroy(synx_class);
del_cdev:
	cdev_del(&synx_cdev);
unreg_chrdev:
	unregister_chrdev_region(synx_dev, 1);
	return ret;
}

static void __exit msm_synx_exit(void)
{
	unregister_pm_notifier(&qcom_synx_notif_block);
	device_destroy(synx_class, synx_dev);
	class_destroy(synx_class);
	cdev_del(&synx_cdev);
	unregister_chrdev_region(synx_dev, 1);
}

module_init(msm_synx_init);
module_exit(msm_synx_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Qualcomm Global Synx Driver Mock");
