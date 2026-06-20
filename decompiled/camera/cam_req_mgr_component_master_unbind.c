__int64 __fastcall cam_req_mgr_component_master_unbind(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0

  component_unbind_all(a1, 0);
  sysfs_remove_file_ns(a1, &camera_debug_sysfs_attr, 0);
  v2 = cam_req_mgr_core_device_deinit();
  cam_req_mgr_util_deinit(v2);
  media_device_unregister(*(_QWORD *)(qword_2FDA58 + 8));
  media_device_cleanup(*(_QWORD *)(qword_2FDA58 + 8));
  v3 = *(_QWORD *)(qword_2FDA58 + 8);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  v4 = g_dev;
  *(_QWORD *)(qword_2FDA58 + 8) = 0;
  video_unregister_device(v4);
  video_device_release(g_dev);
  g_dev = 0;
  v4l2_device_unregister(qword_2FDA58);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(qword_2FDA58, 0);
  else
    kvfree(qword_2FDA58);
  qword_2FDA58 = 0;
  v5 = kmem_cache_destroy(g_cam_req_mgr_timer_cachep);
  g_cam_req_mgr_timer_cachep = 0;
  result = cam_req_mgr_debug_bind_latency_cleanup(v5);
  byte_2FDA98 = 0;
  return result;
}
