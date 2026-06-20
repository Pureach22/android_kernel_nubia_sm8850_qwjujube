#ifndef __KGSL_IOMMU_H
#define __KGSL_IOMMU_H

#include <linux/iommu.h>
#include <linux/regulator/consumer.h>
#include <linux/adreno-smmu-priv.h>
#include "kgsl_mmu.h"

#define KGSL_IOMMU_NAME_SIZE 32
#define KGSL_IOMMU_REG_SIZE 16
#define KGSL_IOMMU_CONTEXT_SIZE 2
#define KGSL_IOMMU_PAGEFAULT_TYPES 32
#define KGSL_IOMMU_MAX_PF_PROCS 2

#define KGSL_IOMMU_ASID_START_BIT 48

#define KGSL_IOMMU_VA_BASE64 0x4000000000ULL
#define KGSL_IOMMU_VA_END64   0x8000000000ULL

#define KGSL_IOMMU_SVM_BASE64 0x1000000000ULL
#define KGSL_IOMMU_SVM_END64   0x4000000000ULL

#define KGSL_IOMMU_SVM_BASE32(mmu) 0x400000ULL
#define KGSL_IOMMU_SVM_END32(mmu)   0xea5ff000ULL

#define KGSL_IOMMU_GLOBAL_MEM_BASE(mmu) 0x8000000000ULL

#define KGSL_IOMMU_SECURE_BASE32 0x400000
#define KGSL_IOMMU_SECURE_BASE(mmu) 0x400000ULL

/* SCTLR bits */
#define KGSL_IOMMU_SCTLR_CFIE_SHIFT 1
#define KGSL_IOMMU_SCTLR_CFCFG_SHIFT 7
#define KGSL_IOMMU_SCTLR_HUPCF_SHIFT 8

/* ACTLR bits */
#define KGSL_IOMMU_ACTLR_PRR_ENABLE BIT(5)

/* PRR registers */
#define KGSL_IOMMU_PRR_CFG_LADDR 0x6000
#define KGSL_IOMMU_PRR_CFG_UADDR 0x6004

/* Global memory size */
#define KGSL_IOMMU_GLOBAL_MEM_SIZE SZ_1M

/* FSR bits */
#define KGSL_IOMMU_FSR_TRANSLATION_FORMAT_MASK BIT(30)

/* Memstore tokens */
#define KGSL_MEMSTORE_TOKEN_ADDRESS 0xFFFFFFFFFFFFFFFFULL

struct kgsl_iommu_reg {
	char name[KGSL_IOMMU_NAME_SIZE];
	u32 offset;
	u32 val;
};

struct kgsl_iommu_context {
	const char *name;
	u32 id;
	u32 cb_num;
	u32 asid;
	u32 _pad1;
	u64 pt_base;
	u32 pf_count;
	u32 _pad2;
	struct ratelimit_state ratelimit;
	u32 pf_type_counts[KGSL_IOMMU_PAGEFAULT_TYPES];
	struct iommu_domain *domain;
	struct kgsl_device *kgsldev;
	struct platform_device *pdev;
	struct adreno_smmu_priv adreno_smmu;
	bool stalled_on_fault;
};

struct kgsl_iommu_pf_proc {
	pid_t pid;
	char comm[16];
	u32 pf_count;
	u32 pf_type_counts[KGSL_IOMMU_PAGEFAULT_TYPES];
};

struct kgsl_iommu {
	char name[KGSL_IOMMU_NAME_SIZE];
	struct device_node *node;
	struct kgsl_iommu_reg *reg_list;
	u32 reg_count;
	struct regulator *cx_regulator;
	u32 pf_type_counts[KGSL_IOMMU_PAGEFAULT_TYPES];
	struct kgsl_iommu_context user_context;
	struct kgsl_iommu_context secure_context;
	struct kgsl_iommu_context lpac_context;
	void __iomem *regbase;
	phys_addr_t regstart;
	size_t regsize;
	struct kgsl_memdesc *setstate;
	atomic_t clk_enable_count;
	struct clk_bulk_data *clks;
	int num_clks;
	struct kgsl_memdesc *smmu_info;
	struct kgsl_iommu_pf_proc pf_procs[KGSL_IOMMU_MAX_PF_PROCS];
	u32 cb0_offset;
	u32 pagesize;
	struct platform_device *pdev;
	rwlock_t pf_stats_lock;
};

static inline u64 KGSL_IOMMU_SECURE_SIZE(struct kgsl_mmu *mmu)
{
	return (u64)2048 * SZ_4K;
}

#endif
