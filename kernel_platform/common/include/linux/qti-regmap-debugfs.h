/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_QTI_REGMAP_DEBUGFS_H
#define _LINUX_QTI_REGMAP_DEBUGFS_H

struct device;
struct regmap;

#if IS_ENABLED(CONFIG_DEBUG_FS)
void devm_regmap_qti_debugfs_register(struct device *dev, struct regmap *map);
#else
static inline void devm_regmap_qti_debugfs_register(struct device *dev, struct regmap *map) {}
#endif

#endif /* _LINUX_QTI_REGMAP_DEBUGFS_H */
