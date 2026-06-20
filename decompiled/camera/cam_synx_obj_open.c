__int64 cam_synx_obj_open()
{
  __int64 v0; // x0

  mutex_lock(g_cam_synx_obj_dev + 23560);
  if ( (cam_sync_monitor_mask & 8) != 0 )
  {
    if ( mem_trace_en == 1 )
      v0 = cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_synx_obj_open", 0x314u);
    else
      v0 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(g_cam_synx_obj_dev + 23640) = v0;
    if ( !v0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000000LL,
        2,
        "cam_synx_obj_open",
        792,
        "Failed to allocate memory %d",
        16);
  }
  return mutex_unlock(g_cam_synx_obj_dev + 23560);
}
