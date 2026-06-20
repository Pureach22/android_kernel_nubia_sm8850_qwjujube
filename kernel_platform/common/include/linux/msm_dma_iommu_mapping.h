/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _MSM_DMA_IOMMU_MAPPING_H
#define _MSM_DMA_IOMMU_MAPPING_H

#include <linux/device.h>
#include <linux/dma-direction.h>
#include <linux/scatterlist.h>
#include <linux/dma-buf.h>

int msm_dma_map_sg_attrs(struct device *dev, struct scatterlist *sg, int nents,
			 enum dma_data_direction dir, struct dma_buf *dma_buf,
			 unsigned long attrs);

void msm_dma_unmap_sg_attrs(struct device *dev, struct scatterlist *sg, int nents,
			   enum dma_data_direction dir, struct dma_buf *dma_buf,
			   unsigned long attrs);

int msm_dma_unmap_all_for_dev(struct device *dev);

void msm_dma_buf_freed(void *buffer);

#endif /* _MSM_DMA_IOMMU_MAPPING_H */
