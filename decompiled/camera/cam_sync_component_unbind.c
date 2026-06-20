_QWORD *cam_sync_component_unbind()
{
  __int64 v0; // x21
  _QWORD *v1; // x0
  _QWORD *v2; // x0
  __int64 v3; // x0
  __int64 i; // x8
  _QWORD *result; // x0

  v4l2_device_unregister(*(_QWORD *)(*(_QWORD *)sync_dev + 1104LL));
  v0 = sync_dev;
  media_device_unregister(*(_QWORD *)(sync_dev + 16));
  media_device_cleanup(*(_QWORD *)(v0 + 16));
  v1 = *(_QWORD **)(v0 + 16);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_free(v1, 0);
  else
    v2 = (_QWORD *)kvfree(v1);
  cam_synx_obj_driver_deinit(v2);
  video_unregister_device(*(_QWORD *)sync_dev);
  v3 = video_device_release(*(_QWORD *)sync_dev);
  *(_QWORD *)(sync_dev + 8384) = 0;
  cam_dma_fence_driver_deinit(v3);
  for ( i = 34; i != 2082; ++i )
    *(_DWORD *)(sync_dev + 4 * i) = 0;
  vfree(*(_QWORD *)(sync_dev + 128));
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)sync_dev, 0);
  else
    result = (_QWORD *)kvfree(sync_dev);
  sync_dev = 0;
  return result;
}
