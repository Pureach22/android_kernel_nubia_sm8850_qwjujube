/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_QCOM_IO_PGTABLE_H
#define _LINUX_QCOM_IO_PGTABLE_H

#include <linux/io-pgtable.h>
#include <linux/iommu.h>

/* QCOM IOMMU Attributes */
#define IOMMU_SYS_CACHE_NWA (1 << 0)
#define IO_PGTABLE_QUIRK_QCOM_USE_LLC_NWA BIT(3)
#define QCOM_ARM_64_LPAE_S1 10
#ifndef QCOM_IOMMU_FAULT_MODEL_NON_FATAL
#define QCOM_IOMMU_FAULT_MODEL_NON_FATAL 1
#endif


struct qcom_io_pgtable_info {
	struct io_pgtable_cfg	cfg;
	unsigned int		asid;
	u64			ttbr0;
	u64			tcr;
	u64			mair;
};

int qcom_arm_lpae_map_sg(struct io_pgtable_ops *ops, unsigned long iova,
			 struct scatterlist *sg, unsigned int nents, int prot,
			 gfp_t gfp, size_t *mapped);

size_t qcom_arm_lpae_unmap_pages(struct io_pgtable_ops *ops, unsigned long iova,
				 size_t pgsize, size_t pgcount,
				 struct iommu_iotlb_gather *gather);

void qcom_skip_tlb_management(struct device *dev, bool skip);
int qcom_iommu_get_context_bank_nr(struct iommu_domain *domain);
int qcom_iommu_get_asid_nr(struct iommu_domain *domain);
void qcom_free_io_pgtable_ops(struct io_pgtable_ops *ops);
struct io_pgtable_ops *qcom_alloc_io_pgtable_ops(int fmt, void *cfg, void *cookie);
int qcom_iommu_set_secure_vmid(struct iommu_domain *domain, int vmid);

#endif
