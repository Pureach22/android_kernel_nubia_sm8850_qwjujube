/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_MSM_ION_H
#define _LINUX_MSM_ION_H

#include <linux/types.h>

#define ION_BIT(nr) (1UL << (nr))

/* Heap IDs */
#define ION_SYSTEM_HEAP_ID		25
#define ION_CAMERA_HEAP_ID		20
#define ION_SECURE_DISPLAY_HEAP_ID	10
#define ION_AUDIO_HEAP_ID		28

/* Heap Flags */
#define ION_FLAG_CACHED			ION_BIT(0)
#define ION_FLAG_SECURE			ION_BIT(31)

/* Content Protection flags */
#define ION_FLAG_CP_TOUCH		ION_BIT(17)
#define ION_FLAG_CP_BITSTREAM		ION_BIT(18)
#define ION_FLAG_CP_PIXEL		ION_BIT(19)
#define ION_FLAG_CP_NON_PIXEL		ION_BIT(20)
#define ION_FLAG_CP_CAMERA		ION_BIT(21)
#define ION_FLAG_CP_SEC_DISPLAY		ION_BIT(25)
#define ION_FLAG_CP_APP			ION_BIT(26)
#define ION_FLAG_CP_CDSP		ION_BIT(29)

#define ION_HEAP(bit)			ION_BIT(bit)

#endif /* _LINUX_MSM_ION_H */
