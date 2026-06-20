/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _LINUX_MAILBOX_QMP_H
#define _LINUX_MAILBOX_QMP_H

#include <linux/soc/qcom/qcom_aoss.h>

/* 
 * The graphics driver uses qmp_handle as an alias for the AOSS qmp struct.
 * Signatures in qcom_aoss.h match the expected usage in adreno_gen8_gmu.c.
 */
typedef struct qmp qmp_handle;

struct qmp_pkt {
	u32 size;
	void *data;
};

#endif /* _LINUX_MAILBOX_QMP_H */
