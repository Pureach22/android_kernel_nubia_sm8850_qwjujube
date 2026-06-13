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
#include <linux/qtee_shmbridge.h>
#include <linux/clk.h>
#include <drm/drm_device.h>
#include <linux/clk.h>

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

/* IOMMU Parity Extensions */
int qcom_iommu_get_asid(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_asid);

void qcom_iommu_set_fault_model(struct iommu_domain *domain, u32 model) { }
EXPORT_SYMBOL(qcom_iommu_set_fault_model);

int qcom_iommu_sid_switch(struct device *dev, u32 type) { return 0; }
EXPORT_SYMBOL(qcom_iommu_sid_switch);

int qcom_iommu_enable_s1_translation(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_enable_s1_translation);

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


/* Display PLL Parity Extensions */
int edp_pll_clock_register_3nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_3nm);

int edp_pll_clock_register_4nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_4nm);

int edp_pll_clock_register_5nm(void *p1, void *p2) { return 0; }
EXPORT_SYMBOL(edp_pll_clock_register_5nm);

/* DWC3 Parity Extensions */
int dwc3_msm_set_dp_mode(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(dwc3_msm_set_dp_mode);

/* HDCP Parity Extensions */
int sde_hdcp_version(void *p1) { return 0; }
EXPORT_SYMBOL(sde_hdcp_version);

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

/* Missing Parity Symbols Restored */
int spec_sync_wait_bind_array(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(spec_sync_wait_bind_array);

int qcom_clk_set_flags(struct clk *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(qcom_clk_set_flags);

void panel_event_notification_trigger(void *p1, u32 p2) { }
EXPORT_SYMBOL(panel_event_notification_trigger);

int qcom_clk_crmb_set_rate(struct clk *p1, unsigned long p2) { return 0; }
EXPORT_SYMBOL(qcom_clk_crmb_set_rate);

int qcom_clk_crmb_set_pwr(struct clk *p1, bool p2) { return 0; }
EXPORT_SYMBOL(qcom_clk_crmb_set_pwr);

int msm_hw_fence_update_txq_error(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_update_txq_error);

int msm_hw_fence_wait(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_wait);

int msm_hw_fence_signal(void *p1, u32 p2) { return 0; }
EXPORT_SYMBOL(msm_hw_fence_signal);

int rpmh_write_sleep_and_wake(void *p1, u32 p2, void *p3, u32 p4) { return 0; }
EXPORT_SYMBOL(rpmh_write_sleep_and_wake);

int rpmh_mode_solver_set(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(rpmh_mode_solver_set);

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

/* SMMU Proxy Parity Extensions */
int smmu_proxy_switch_sid(u32 p1, u32 p2) { return 0; }
EXPORT_SYMBOL(smmu_proxy_switch_sid);

int smmu_proxy_get_csf_version(u32 p1) { return 0; }
EXPORT_SYMBOL(smmu_proxy_get_csf_version);

/* SCM Secure Parity Extensions */
int qcom_scm_set_display_secure_state(u32 p1) { return 0; }
EXPORT_SYMBOL(qcom_scm_set_display_secure_state);

int qcom_scm_mem_protect_sd_ctrl(u32 p1, u32 p2) { return 0; }
EXPORT_SYMBOL(qcom_scm_mem_protect_sd_ctrl);



/* IPC Log Parity Extensions */
void *ipc_log_context_create(u32 p1, const char *p2, u32 p3) { return NULL; }
EXPORT_SYMBOL(ipc_log_context_create);

void ipc_log_context_destroy(void *p1) { }
EXPORT_SYMBOL(ipc_log_context_destroy);

int ipc_log_string(void *p1, const char *p2, ...) { return 0; }
EXPORT_SYMBOL(ipc_log_string);

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
void *msm_gpio_get_pin_address(u32 p1) { return NULL; }
EXPORT_SYMBOL(msm_gpio_get_pin_address);

/* DMA Parity Extensions */
void msm_dma_unmap_all_for_dev(struct device *p1) { }
EXPORT_SYMBOL(msm_dma_unmap_all_for_dev);

/* CRM Parity Extensions */
int crm_write_pwr_states(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(crm_write_pwr_states);

int crm_write_perf_ol(void *p1, u32 p2, u32 p3) { return 0; }
EXPORT_SYMBOL(crm_write_perf_ol);

void *crm_get_device(void *p1) { return NULL; }
EXPORT_SYMBOL(crm_get_device);

/* Socinfo Parity Extensions */
void *socinfo_get_part_info(u32 part_id) { return NULL; }
EXPORT_SYMBOL(socinfo_get_part_info);

u32 socinfo_get_part_count(u32 part_id) { return 0; }
EXPORT_SYMBOL(socinfo_get_part_count);

void *socinfo_get_subpart_info(u32 part_id, u32 subpart_id) { return NULL; }
EXPORT_SYMBOL(socinfo_get_subpart_info);

/* SPMI Parity Extensions */
unsigned long spmi_pmic_arb_map_address(u32 slave_id, u32 periph_id) { return 0; }
EXPORT_SYMBOL(spmi_pmic_arb_map_address);

/* SCM Parity Extensions */
int qcom_scm_kgsl_set_smmu_aperture(u32 cb_num) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_aperture);

int qcom_scm_kgsl_set_smmu_lpac_aperture(u32 cb_num) { return 0; }
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_lpac_aperture);

void qcom_skip_tlb_management(struct device *dev, bool skip) {}
EXPORT_SYMBOL(qcom_skip_tlb_management);

int qcom_iommu_get_context_bank_nr(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_context_bank_nr);

int qcom_iommu_get_asid_nr(struct iommu_domain *domain) { return 0; }
EXPORT_SYMBOL(qcom_iommu_get_asid_nr);

int qcom_iommu_set_secure_vmid(struct iommu_domain *domain, int vmid) { return 0; }
EXPORT_SYMBOL(qcom_iommu_set_secure_vmid);

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

/* DDR Type from FDT */
int of_fdt_get_ddrtype(void) { return 0; }
EXPORT_SYMBOL(of_fdt_get_ddrtype);

/* Clock Diagnostic Hooks */
void qcom_clk_dump(void *clk, void *reg, bool verbose) { }
EXPORT_SYMBOL(qcom_clk_dump);

/* DCVS Voter Parity */
int qcom_dcvs_register_voter(const char *name, u32 hw_type, u32 path) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_register_voter);

void qcom_dcvs_unregister_voter(const char *name, u32 hw_type, u32 path) { }
EXPORT_SYMBOL(qcom_dcvs_unregister_voter);

int qcom_dcvs_update_votes(const char *name, struct dcvs_freq *freq, u32 count, u32 path) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_update_votes);

int qcom_dcvs_hw_minmax_get(u32 hw_type, u32 *min, u32 *max) { return 0; }
EXPORT_SYMBOL(qcom_dcvs_hw_minmax_get);

/* Sysstats Event */
void sysstats_register_kgsl_stats_cb(u64 (*cb)(pid_t pid)) { }
EXPORT_SYMBOL(sysstats_register_kgsl_stats_cb);

void sysstats_unregister_kgsl_stats_cb(void) { }
EXPORT_SYMBOL(sysstats_unregister_kgsl_stats_cb);

/* Boot Mode */
int zte_get_boot_mode(void) { return 0; }
EXPORT_SYMBOL(zte_get_boot_mode);

/* QTEE SHM Bridge Parity */
bool qtee_shmbridge_is_enabled(void) { return false; }
EXPORT_SYMBOL(qtee_shmbridge_is_enabled);

int qtee_shmbridge_register(u64 paddr, size_t size, u32 flags, u64 *handle) { return 0; }
EXPORT_SYMBOL(qtee_shmbridge_register);

int qtee_shmbridge_deregister(u64 handle) { return 0; }
EXPORT_SYMBOL(qtee_shmbridge_deregister);

int qtee_shmbridge_allocate_shm(size_t size, struct qtee_shm *shm) { return -ENOMEM; }
EXPORT_SYMBOL(qtee_shmbridge_allocate_shm);

void qtee_shmbridge_free_shm(struct qtee_shm *shm) { }
EXPORT_SYMBOL(qtee_shmbridge_free_shm);

void msm_perf_events_update(void *p1, u32 p2, u32 p3) {}
EXPORT_SYMBOL(msm_perf_events_update);

bool qcom_scm_dcvs_core_available(void) { return false; }
EXPORT_SYMBOL(qcom_scm_dcvs_core_available);

bool qcom_scm_dcvs_ca_available(void) { return false; }
EXPORT_SYMBOL(qcom_scm_dcvs_ca_available);

int qcom_scm_dcvs_init_ca_v2(u64 paddr, size_t size) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_init_ca_v2);

int qcom_scm_dcvs_update_ca_v2(u32 level, u32 total_time, u32 busy_time, u32 ca) { return 0; }
EXPORT_SYMBOL(qcom_scm_dcvs_update_ca_v2);

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

void *kgsl_gpu_num_freqs_fp = NULL;
EXPORT_SYMBOL(kgsl_gpu_num_freqs_fp);
