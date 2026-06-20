#ifndef _MSM_HW_FENCE_H_
#define _MSM_HW_FENCE_H_

#include <linux/types.h>
#include <soc/qcom/synx_api.h>

#define MSM_HW_FENCE_UPDATE_ERROR_WITH_MOVE 1

struct msm_hw_fence_cb_data {
    void *data;
};

extern int msm_hw_fence_update_txq_error(void *client, u64 handle, u32 error, u32 flags);
extern int msm_hw_fence_register_error_cb(void *client, void (*cb)(u32, int, void *), void *data);

#endif
