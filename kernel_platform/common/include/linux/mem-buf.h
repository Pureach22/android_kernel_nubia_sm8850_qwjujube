/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_MEM_BUF_H
#define _LINUX_MEM_BUF_H

#include <linux/types.h>
#include <linux/dma-buf.h>

struct mem_buf_lend_kernel_arg {
	u32 nr_acl_entries;
	int *vmids;
	int *perms;
	u32 handle;
};

struct mem_buf_retrieve_kernel_arg {
	u32 sender_vmid;
	u32 nr_acl_entries;
	int *vmids;
	int *perms;
	u32 memparcel_hdl;
	u32 fd_flags;
};

/* API Prototypes */
int mem_buf_dma_buf_copy_vmperm(struct dma_buf *dmabuf, int **vmid_list, int **perms_list, int *nelems);
bool mem_buf_dma_buf_exclusive_owner(struct dma_buf *dmabuf);
int mem_buf_lend(struct dma_buf *dmabuf, struct mem_buf_lend_kernel_arg *arg);
int mem_buf_dma_buf_get_memparcel_hdl(struct dma_buf *dmabuf, u32 *hdl);
int mem_buf_dma_buf_set_destructor(struct dma_buf *dmabuf, int (*destructor)(void *), void *pvt);
struct dma_buf *mem_buf_retrieve(struct mem_buf_retrieve_kernel_arg *arg);

#endif /* _LINUX_MEM_BUF_H */
