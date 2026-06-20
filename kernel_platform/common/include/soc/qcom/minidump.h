/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __QCOM_MINIDUMP_H__
#define __QCOM_MINIDUMP_H__

#include <linux/types.h>
#include <linux/notifier.h>

#define MAX_MINIDUMP_NAME_LEN 32

struct md_region {
	char name[MAX_MINIDUMP_NAME_LEN];
	u64 virt_addr;
	u64 phys_addr;
	u64 size;
};

struct va_md_entry {
	char owner[MAX_MINIDUMP_NAME_LEN];
	u64 vaddr;
	u64 size;
	void (*cb)(void *dst, unsigned long len);
};

#ifdef CONFIG_QCOM_VA_MINIDUMP
bool msm_minidump_enabled(void);
int msm_minidump_add_region(const struct md_region *region);
int msm_minidump_remove_region(const struct md_region *region);
int msm_minidump_update_region(const struct md_region *region);

bool qcom_va_md_enabled(void);
int qcom_va_md_add_region(struct va_md_entry *entry);
int qcom_va_md_register(const char *name, struct notifier_block *nb);
int qcom_va_md_unregister(const char *name, struct notifier_block *nb);
#else
static inline bool msm_minidump_enabled(void)
{
	return false;
}

static inline int msm_minidump_add_region(const struct md_region *region)
{
	return -ENODEV;
}

static inline int msm_minidump_remove_region(const struct md_region *region)
{
	return -ENODEV;
}

static inline int msm_minidump_update_region(const struct md_region *region)
{
	return -ENODEV;
}

static inline bool qcom_va_md_enabled(void)
{
	return false;
}

static inline int qcom_va_md_add_region(struct va_md_entry *entry)
{
	return -ENODEV;
}

static inline int qcom_va_md_register(const char *name, struct notifier_block *nb)
{
	return -ENODEV;
}

static inline int qcom_va_md_unregister(const char *name, struct notifier_block *nb)
{
	return -ENODEV;
}
#endif

#endif /* __QCOM_MINIDUMP_H__ */
