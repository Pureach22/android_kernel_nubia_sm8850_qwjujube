#ifndef _SYNX_API_H_
#define _SYNX_API_H_

#include <linux/types.h>
#include <linux/dma-fence.h>
#include <linux/dma-fence-array.h>

enum synx_client_id {
    SYNX_CLIENT_HW_FENCE_DPU0_CTL0 = 100,
    SYNX_CLIENT_HW_FENCE_GFX_CTX0 = 106,
    SYNX_CLIENT_MAX = 200,
};

struct synx_session {
    void *client;
    int type;
};

#ifndef SYNX_RESOURCE_SOCCP
#define SYNX_RESOURCE_SOCCP 10
#endif
#ifndef SYNX_CREATE_DMA_FENCE
#define SYNX_CREATE_DMA_FENCE BIT(0)
#endif

struct synx_queue_desc {
    void *vaddr;
    u64 dev_addr;
    size_t size;
};

struct synx_hw_fence_hfi_queue_table_header {
    u32 qhdr0_offset;
};

struct synx_hw_fence_hfi_queue_header {
    u32 tx_wm;
    u32 write_index;
};

struct synx_initialization_params {
    enum synx_client_id id;
    void *ptr;
};

struct synx_create_params {
    u32 flags;
    u32 *h_synx;
    struct dma_fence *fence;
};

struct synx_import_params {
    u32 type;
    union {
        struct {
            u32 flags;
            int fd;
            struct dma_fence *fence;
            u32 *new_h_synx;
        } indv;
    };
};

#ifndef SYNX_IMPORT_INDV_PARAMS
#define SYNX_IMPORT_INDV_PARAMS 1
#endif
#ifndef SYNX_IMPORT_DMA_FENCE
#define SYNX_IMPORT_DMA_FENCE   BIT(0)
#endif

#ifndef SYNX_STATE_SIGNALED_SUCCESS
#define SYNX_STATE_SIGNALED_SUCCESS 0x1
#endif

/* External definitions for binary parity */
extern struct synx_session *synx_initialize(struct synx_initialization_params *params);
extern int synx_uninitialize(struct synx_session *handle);
extern int synx_create(struct synx_session *handle, struct synx_create_params *params);
extern int synx_release(struct synx_session *handle, u32 synx_obj);
extern int synx_signal(struct synx_session *handle, u32 synx_obj, u32 status);
extern int synx_import(struct synx_session *handle, struct synx_import_params *params);
extern int synx_wait(u32 synx_obj, u64 timeout_ms);
extern int synx_get_status(u32 synx_obj, u32 *status);
extern int synx_enable_resources(u32 client, u32 resource, unsigned long data);
extern int synx_recover(int type);

#ifndef SPEC_FENCE_FLAG_FENCE_ARRAY
#define SPEC_FENCE_FLAG_FENCE_ARRAY       0x10
#endif
#ifndef SPEC_FENCE_FLAG_FENCE_ARRAY_BOUND
#define SPEC_FENCE_FLAG_FENCE_ARRAY_BOUND 0x11
#endif
#ifndef SYNX_HW_FENCE_FLAG_ENABLED_BIT
#define SYNX_HW_FENCE_FLAG_ENABLED_BIT    (1 << 2)
#endif
#ifndef SPEC_FENCE_TIMEOUT_MS
#define SPEC_FENCE_TIMEOUT_MS             1000
#endif

extern int spec_sync_wait_bind_array(void *a, int t);

#ifndef ipc_log_string
#include <linux/ipc_logging.h>
#endif

#endif
