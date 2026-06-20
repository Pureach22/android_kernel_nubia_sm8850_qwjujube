__int64 *get_synx_fence_ops()
{
  get_synx_fence_ops_synx_ops = (__int64)msm_vidc_synx_fence_register;
  qword_9EA30 = (__int64)msm_vidc_synx_fence_deregister;
  qword_9EA38 = (__int64)msm_vidc_synx_fence_create;
  qword_9EA40 = (__int64)msm_vidc_synx_fence_import;
  qword_9EA48 = (__int64)msm_vidc_synx_fence_create_fd;
  qword_9EA50 = (__int64)msm_vidc_synx_fence_destroy_fd;
  qword_9EA58 = (__int64)msm_vidc_synx_fence_destroy;
  qword_9EA60 = (__int64)msm_vidc_synx_fence_release;
  qword_9EA68 = (__int64)msm_vidc_synx_fence_recover;
  qword_9EA70 = (__int64)msm_vidc_synx_fence_enable_resources;
  return &get_synx_fence_ops_synx_ops;
}
