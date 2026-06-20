/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_PINCTRL_QCOM_PINCTRL_H
#define _LINUX_PINCTRL_QCOM_PINCTRL_H

#include <linux/types.h>
#include <linux/ioport.h>

bool msm_gpio_get_pin_address(unsigned int pin, struct resource *res);
int msm_gpio_mpm_wake_set(unsigned int gpio, bool enable);

#endif /* _LINUX_PINCTRL_QCOM_PINCTRL_H */
