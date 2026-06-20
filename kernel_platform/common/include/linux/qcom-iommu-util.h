/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2016-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __QCOM_IOMMU_UTIL_H__
#define __QCOM_IOMMU_UTIL_H__

#include <linux/device.h>
#include <linux/iommu.h>

#define QCOM_IOMMU_FAULT_MODEL_NON_FATAL BIT(0)
#define QCOM_IOMMU_FAULT_MODEL_NO_CFRE    BIT(1)
#define QCOM_IOMMU_FAULT_MODEL_NO_STALL   BIT(2)
#define QCOM_IOMMU_FAULT_MODEL_HUPCF      BIT(3)

#define IOMMU_FAULT_TRANSLATION (1 << 0)
#define IOMMU_FAULT_PERMISSION  (1 << 1)
#define IOMMU_FAULT_EXTERNAL    (1 << 2)
#define IOMMU_FAULT_TRANSACTION_STALLED BIT(31)



enum sid_switch_direction {
	SID_ACQUIRE,
	SID_RELEASE,
};

struct qcom_iommu_fault_ids {
	uint32_t bid;
	uint32_t pid;
	uint32_t mid;
};

#ifdef CONFIG_QCOM_IOMMU_UTIL
int qcom_iommu_sid_switch(struct device *dev, enum sid_switch_direction dir);
int qcom_iommu_enable_s1_translation(struct iommu_domain *domain);
int qcom_iommu_set_fault_model(struct iommu_domain *domain, int fault_model);
int qcom_iommu_get_context_bank_nr(struct iommu_domain *domain);
int qcom_iommu_get_asid_nr(struct iommu_domain *domain);
int qcom_iommu_set_secure_vmid(struct iommu_domain *domain, int secure_vmid);
int qcom_iommu_get_mappings_configuration(struct iommu_domain *domain);
int qcom_iommu_get_fault_ids(struct iommu_domain *domain, struct qcom_iommu_fault_ids *ids);
#else
static inline int qcom_iommu_sid_switch(struct device *dev, enum sid_switch_direction dir)
{
	return 0;
}

static inline int qcom_iommu_enable_s1_translation(struct iommu_domain *domain)
{
	return 0;
}

static inline int qcom_iommu_set_fault_model(struct iommu_domain *domain, int fault_model)
{
	return 0;
}

static inline int qcom_iommu_get_context_bank_nr(struct iommu_domain *domain)
{
	return -ENODEV;
}

static inline int qcom_iommu_get_asid_nr(struct iommu_domain *domain)
{
	return -ENODEV;
}

static inline int qcom_iommu_set_secure_vmid(struct iommu_domain *domain, int secure_vmid)
{
	return 0;
}

static inline int qcom_iommu_get_mappings_configuration(struct iommu_domain *domain)
{
	return 0;
}

static inline int qcom_iommu_get_fault_ids(struct iommu_domain *domain, struct qcom_iommu_fault_ids *ids)
{
	if (ids) {
		ids->bid = 0;
		ids->pid = 0;
		ids->mid = 0;
	}
	return -ENODEV;
}
#endif

#endif /* __QCOM_IOMMU_UTIL_H__ */
