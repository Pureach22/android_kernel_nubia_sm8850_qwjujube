_QWORD *cam_dma_fence_driver_deinit()
{
  _QWORD *result; // x0

  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)g_cam_dma_fence_dev, 0);
  else
    result = (_QWORD *)kvfree(g_cam_dma_fence_dev);
  g_cam_dma_fence_dev = 0;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       debug_mdl & 0x400000000LL,
                       4,
                       "cam_dma_fence_driver_deinit",
                       890,
                       "Camera DMA fence driver deinitialized");
  return result;
}
