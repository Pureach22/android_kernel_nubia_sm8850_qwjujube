#ifndef _LINUX_IPC_LOGGING_H
#define _LINUX_IPC_LOGGING_H

#include <linux/types.h>

struct ipc_log_context;

void *ipc_log_context_create(int max_num_pages, const char *name, uint16_t flags);
void ipc_log_context_destroy(void *ctxt);
int ipc_log_string(void *ctxt, const char *fmt, ...);
int ipc_log_write(void *ctxt, const char *data, int len);
int ipc_log_extract(void *ctxt, char *buf, int len);

/* Protocol Encoding */
void *msg_encode_start(void *v_ctx, uint32_t msg_type);
void msg_encode_end(void *v_ctx, void *v_msg);

/* TSV (Tag-Size-Value) Logging */
void tsv_timestamp_write(void *v_ctx, uint64_t timestamp);
void tsv_pointer_write(void *v_ctx, void *ptr);
void tsv_int32_write(void *v_ctx, int32_t val);
void tsv_byte_array_write(void *v_ctx, const void *data, uint32_t len);

#endif /* _LINUX_IPC_LOGGING_H */
