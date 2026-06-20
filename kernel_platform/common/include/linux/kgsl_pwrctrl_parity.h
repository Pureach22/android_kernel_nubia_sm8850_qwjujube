/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_KGSL_PWRCTRL_PARITY_H
#define _LINUX_KGSL_PWRCTRL_PARITY_H

#include <linux/types.h>

/* Proprietary ZTE/Qualcomm power control functions */
void kgsl_pwrctrl_set_max_level(u32 level);
void kgsl_pwrctrl_set_min_level(u32 level);
u32 kgsl_pwrctrl_get_max_level(void);
u32 kgsl_pwrctrl_get_min_level(void);
int kgsl_pwrctrl_get_gpu_loading(void);

#endif /* _LINUX_KGSL_PWRCTRL_PARITY_H */
