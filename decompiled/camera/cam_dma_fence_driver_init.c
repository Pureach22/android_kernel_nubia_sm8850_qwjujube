__int64 cam_dma_fence_driver_init()
{
  __int64 v0; // x0
  __int64 v1; // x20
  __int64 result; // x0
  unsigned __int64 v9; // x9

  if ( mem_trace_en == 1 )
    v0 = cam_mem_trace_alloc(25168, 0xCC0u, 0, "cam_dma_fence_driver_init", 0x363u);
  else
    v0 = _kvmalloc_node_noprof(25168, 0, 3520, 0xFFFFFFFFLL);
  g_cam_dma_fence_dev = v0;
  if ( !v0 )
    return 4294967284LL;
  _mutex_init(v0 + 25096, "&g_cam_dma_fence_dev->dev_lock", &cam_dma_fence_driver_init___key);
  v1 = g_cam_dma_fence_dev;
  memset((void *)(g_cam_dma_fence_dev + 24584), 0, 0x200u);
  *(_QWORD *)(v1 + 25144) = 0;
  _X8 = (unsigned __int64 *)(v1 + 25144);
  *(_QWORD *)(v1 + 25152) = 0;
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 1, _X8) );
  *(_QWORD *)g_cam_dma_fence_dev = dma_fence_context_alloc(1);
  result = 0;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "cam_dma_fence_driver_init",
      882,
      "Camera DMA fence driver initialized");
    return 0;
  }
  return result;
}
