_QWORD *cam_smmu_driver_deinit()
{
  qword_3940D8 = (__int64)&qword_3940D8;
  qword_3940E0 = (__int64)&qword_3940D8;
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free((_QWORD *)buf_tracking_pool, 0);
  else
    return (_QWORD *)kvfree(buf_tracking_pool);
}
