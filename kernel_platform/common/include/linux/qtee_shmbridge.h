/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _LINUX_QTEE_SHMBRIDGE_H
#define _LINUX_QTEE_SHMBRIDGE_H

#include <linux/types.h>

struct qtee_shm {
	void *vaddr;
	phys_addr_t paddr;
	size_t size;
};

#ifndef PERM_READ
#define PERM_READ              0x4
#endif
#ifndef PERM_WRITE
#define PERM_WRITE             0x2
#endif
#ifndef PERM_EXEC
#define PERM_EXEC              0x1
#endif
#ifndef VMID_HLOS
#define VMID_HLOS              3
#endif

/* SM8750 QTEE SHM Bridge interfaces */
bool qtee_shmbridge_is_enabled(void);
int qtee_shmbridge_register(phys_addr_t paddr, size_t size, u32 *vmid_list, u32 *perms_list, u32 nelems, int tz_perm, u64 *handle);
int qtee_shmbridge_deregister(u64 handle);
int qtee_shmbridge_allocate_shm(size_t size, struct qtee_shm *shm);
void qtee_shmbridge_free_shm(struct qtee_shm *shm);
int qtee_shmbridge_query(phys_addr_t paddr);
void qtee_shmbridge_flush_shm_buf(struct qtee_shm *shm);
void qtee_shmbridge_inv_shm_buf(struct qtee_shm *shm);

int qcom_scm_invoke_smc(phys_addr_t in_paddr, size_t in_buf_len,
			phys_addr_t out_paddr, size_t out_buf_len,
			int32_t *result, u64 *response_type,
			unsigned int *data);

int qcom_scm_invoke_smc_legacy(phys_addr_t in_paddr, size_t in_buf_len,
			       phys_addr_t out_paddr, size_t out_buf_len,
			       int32_t *result, u64 *response_type,
			       unsigned int *data);

int qcom_scm_invoke_callback_response(phys_addr_t out_paddr, size_t out_buf_len,
				      int32_t *result, u64 *response_type,
				      unsigned int *data);

int qcom_scm_get_tz_log_feat_id(u64 *val);
int qcom_scm_get_tz_feat_id_version(u32 feat_id, u64 *val);
int qcom_scm_request_encrypted_log(phys_addr_t paddr, size_t size,
				   u32 log_id, bool supported, bool enabled);
int qcom_scm_query_log_status(u64 *status);
int qcom_scm_query_encrypted_log_feature(u64 *val);
int qcom_scm_register_qsee_log_buf(phys_addr_t paddr, size_t size);

#endif /* _LINUX_QTEE_SHMBRIDGE_H */
