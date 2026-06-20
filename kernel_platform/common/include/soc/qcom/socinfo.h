/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _SOC_QCOM_SOCINFO_H_
#define _SOC_QCOM_SOCINFO_H_

#define qcom_socinfo_feature_code qcom_socinfo_feature_code_GKI
#define SOCINFO_FC_UNKNOWN SOCINFO_FC_UNKNOWN_GKI
#include <linux/soc/qcom/socinfo.h>
#undef qcom_socinfo_feature_code
#undef SOCINFO_FC_UNKNOWN

#include <linux/types.h>

/* Part Info IDs */
enum socinfo_part_id {
	SOCINFO_PART_GPU = 0x1,
	SOCINFO_PART_VIDEO = 0x2,
	SOCINFO_PART_DISPLAY = 0x3,
	SOCINFO_PART_AUDIO = 0x4,
};

/* Feature Code definitions */
enum socinfo_feature_code {
	SOCINFO_FC_UNKNOWN = 0x0,
	SOCINFO_FC_W0 = 0x1,
	SOCINFO_FC_Y0 = 0x2,
	SOCINFO_FC_SUBPART_RESERVE = 0x10,
	SOCINFO_FC_INT_RESERVE = 0x20,
};

/* PCODE definitions */
enum socinfo_pcode {
	SOCINFO_PCODE_UNKNOWN = 0x0,
};

#define PART_GPU SOCINFO_PART_GPU
#define PART_VIDEO SOCINFO_PART_VIDEO
#define PART_DISPLAY SOCINFO_PART_DISPLAY
#define PART_AUDIO SOCINFO_PART_AUDIO

/* SM8750 (Sun) specific socinfo interfaces */
u32 socinfo_get_partinfo_chip_id(enum socinfo_part_id part);
const char *socinfo_get_partinfo_part_name(enum socinfo_part_id part);
u32 socinfo_get_partinfo_vulkan_id(enum socinfo_part_id part);
u32 socinfo_get_feature_code(void);
u32 socinfo_get_pcode(void);

u32 socinfo_get_id(void);
u32 socinfo_get_version(void);
char *socinfo_get_build_id(void);

void *socinfo_get_part_info(u32 part_id);
u32 socinfo_get_part_count(u32 part_id);
void socinfo_get_subpart_info(u32 part_id, void *part_info, u32 count);

#endif /* _SOC_QCOM_SOCINFO_H_ */
