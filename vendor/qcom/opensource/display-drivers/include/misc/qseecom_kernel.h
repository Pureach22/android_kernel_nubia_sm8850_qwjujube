#ifndef _QSEECOM_KERNEL_H_
#define _QSEECOM_KERNEL_H_

struct qseecom_handle {
    void *dev;
};

static inline int qseecom_start_app(struct qseecom_handle **handle, const char *app_name, u32 size) { return 0; }
static inline int qseecom_shutdown_app(struct qseecom_handle **handle) { return 0; }
static inline int qseecom_send_command(struct qseecom_handle *handle, void *send_buf, u32 s_len, void *resp_buf, u32 r_len) { return 0; }

#endif
