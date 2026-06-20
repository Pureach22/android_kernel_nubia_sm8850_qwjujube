/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _SOC_QCOM_SECURE_BUFFER_H_
#define _SOC_QCOM_SECURE_BUFFER_H_

#include <linux/types.h>
#include <linux/scatterlist.h>

/* VMIDs for secure buffer management - SM8750 specific values from msm_drm.ko */
#define VMID_HLOS	3
#define VMID_CP_PIXEL	10
#define VMID_CP_NON_PIXEL 13
#define VMID_CP_CAMERA	14
#define VMID_INLINE_AES	15
#define VMID_CP_BITSTREAM 16
#define VMID_CP_TOUCH	17
#define VMID_CP_CAMERA_PREVIEW 17
#define VMID_CP_SEC_DISPLAY 29
#define VMID_TVM 45
#define VMID_LPASS	0x16
#define VMID_ADSP_HEAP	0x25

#define PERM_READ	0x4
#define PERM_WRITE	0x2
#define PERM_EXEC	0x1

/* 
 * Faithful implementation of hyp_assign_table.
 * In a real system, this communicates with the Hypervisor.
 */
int hyp_assign_table(struct sg_table *table, u32 *source_vmlist,
			int source_nelems, u32 *dest_vmlist,
			int *dest_perms, int dest_nelems);

#endif /* _SOC_QCOM_SECURE_BUFFER_H_ */
