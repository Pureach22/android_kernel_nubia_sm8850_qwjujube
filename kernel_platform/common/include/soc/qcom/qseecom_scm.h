/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __QSEECOM_SCM_H
#define __QSEECOM_SCM_H

#include <linux/types.h>
#include <linux/arm-smccc.h>

#define MAX_SCM_ARGS 10
#define MAX_SCM_RETS 3

struct qseecom_scm_desc {
	u32 arginfo;
	u64 args[MAX_SCM_ARGS];
	u64 ret[MAX_SCM_RETS];
};

#define SCM_SVC_INFO           0x06
#define SCM_SVC_ES             0x10
#define SCM_SVC_TZSCHEDULER    0xFC

#define PERM_READ              0x4
#define PERM_WRITE             0x2
#define PERM_EXEC              0x1

#define VMID_HLOS              3

#define SCM_ARGS_IMPL(num, a, b, c, d, e, f, g, h, i, j, ...) (\
			   (((a) & 0x3) << 4) | \
			   (((b) & 0x3) << 6) | \
			   (((c) & 0x3) << 8) | \
			   (((d) & 0x3) << 10) | \
			   (((e) & 0x3) << 12) | \
			   (((f) & 0x3) << 14) | \
			   (((g) & 0x3) << 16) | \
			   (((h) & 0x3) << 18) | \
			   (((i) & 0x3) << 20) | \
			   (((j) & 0x3) << 22) | \
			   ((num) & 0xf))

#define SCM_ARGS(...) SCM_ARGS_IMPL(__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define SCM_SIP_FNID(s, c) (((((s) & 0xFF) << 8) | ((c) & 0xFF)) | (ARM_SMCCC_OWNER_SIP << 24) | 0x82000000)

int qcom_scm_qseecom_call(u32 smc_id, struct qseecom_scm_desc *desc, bool atomic);

#endif /* __QSEECOM_SCM_H */
