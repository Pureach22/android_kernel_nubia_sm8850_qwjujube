__int64 cam_dma_fence_open()
{
  __int64 v0; // x0
  __int64 result; // x0

  mutex_lock(g_cam_dma_fence_dev + 25096);
  if ( (cam_sync_monitor_mask & 4) != 0 )
  {
    v0 = mem_trace_en == 1
       ? cam_mem_trace_alloc(8, 0xCC0u, 0, "cam_dma_fence_open", 0x351u)
       : _kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(g_cam_dma_fence_dev + 25160) = v0;
    if ( !v0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000000LL,
        2,
        "cam_dma_fence_open",
        853,
        "Failed to allocate memory %d",
        8);
  }
  g_cam_dma_fence_seq_no = 0;
  result = mutex_unlock(g_cam_dma_fence_dev + 25096);
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             debug_mdl & 0x400000000LL,
             4,
             "cam_dma_fence_open",
             860,
             "Camera DMA fence driver opened");
  return result;
}
