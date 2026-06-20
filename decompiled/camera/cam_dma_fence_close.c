__int64 cam_dma_fence_close()
{
  unsigned int v0; // w19
  __int64 v1; // x25
  __int64 i; // x26
  unsigned __int64 v5; // x10
  __int64 v6; // x24
  _QWORD *v7; // x23
  __int64 v8; // x8
  int v15; // w8
  __int64 v16; // x10
  __int64 v17; // x8
  _QWORD **v18; // x9
  _QWORD *v19; // x0
  _QWORD *v20; // x0
  __int64 v21; // x0
  __int64 result; // x0

  mutex_lock(g_cam_dma_fence_dev + 25096);
  v0 = 0;
  v1 = 24584;
  for ( i = 193; i != 24769; i += 192 )
  {
    raw_spin_lock_bh(g_cam_dma_fence_dev + v1);
    v6 = g_cam_dma_fence_dev;
    if ( *(_DWORD *)(g_cam_dma_fence_dev + i - 45) )
    {
      v7 = (_QWORD *)(g_cam_dma_fence_dev + i - 185);
      if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000000LL,
          4,
          "cam_dma_fence_close",
          799,
          "Releasing dma fence seqno: %llu associated with fd: %d[%s] ref_cnt: %u",
          *(_QWORD *)(*(_QWORD *)(g_cam_dma_fence_dev + i - 57) + 40LL),
          *(_DWORD *)(g_cam_dma_fence_dev + i - 49),
          (const char *)(g_cam_dma_fence_dev + i - 185),
          *(_DWORD *)(*(_QWORD *)(g_cam_dma_fence_dev + i - 57) + 56LL));
      if ( *(_BYTE *)(v6 + i - 1) == 1 )
      {
        if ( (cam_sync_monitor_mask & 4) != 0 )
          cam_generic_fence_update_monitor_array(v0, 0, *(_QWORD *)(g_cam_dma_fence_dev + 25160), 6);
        dma_fence_remove_callback(*(_QWORD *)(v6 + i - 57), v6 + i - 41);
      }
      if ( (*(_BYTE *)(v6 + i) & 1) == 0 )
      {
        if ( (cam_sync_monitor_mask & 4) != 0 )
          cam_generic_fence_update_monitor_array(v0, 0, *(_QWORD *)(g_cam_dma_fence_dev + 25160), 4);
        _cam_dma_fence_signal_fence(*(_QWORD **)(v6 + i - 57), 0xFFFFFFBC);
      }
      v8 = *(_QWORD *)(v6 + i - 57);
      if ( v8 )
      {
        _X0 = (unsigned int *)(v8 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v15 = __ldxr(_X0);
        while ( __stlxr(v15 - 1, _X0) );
        if ( v15 == 1 )
        {
          __dmb(9u);
          dma_fence_release();
        }
        else if ( v15 <= 0 )
        {
          refcount_warn_saturate();
        }
      }
      *v7 = 0;
      *(_QWORD *)(v6 + i - 177) = 0;
      v16 = g_cam_dma_fence_dev;
      *(_QWORD *)(v6 + i - 9) = 0;
      *(_QWORD *)(v6 + i - 1) = 0;
      *(_QWORD *)(v6 + i - 25) = 0;
      *(_QWORD *)(v6 + i - 17) = 0;
      *(_QWORD *)(v6 + i - 41) = 0;
      *(_QWORD *)(v6 + i - 33) = 0;
      *(_QWORD *)(v6 + i - 57) = 0;
      *(_QWORD *)(v6 + i - 49) = 0;
      *(_QWORD *)(v6 + i - 73) = 0;
      *(_QWORD *)(v6 + i - 65) = 0;
      *(_QWORD *)(v6 + i - 89) = 0;
      *(_QWORD *)(v6 + i - 81) = 0;
      *(_QWORD *)(v6 + i - 105) = 0;
      *(_QWORD *)(v6 + i - 97) = 0;
      *(_QWORD *)(v6 + i - 121) = 0;
      *(_QWORD *)(v6 + i - 113) = 0;
      *(_QWORD *)(v6 + i - 137) = 0;
      *(_QWORD *)(v6 + i - 129) = 0;
      *(_QWORD *)(v6 + i - 153) = 0;
      *(_QWORD *)(v6 + i - 145) = 0;
      *(_QWORD *)(v6 + i - 169) = 0;
      *(_QWORD *)(v6 + i - 161) = 0;
      _X9 = (unsigned __int64 *)(v16 + 25144 + 8LL * (v0 >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v5 = __ldxr(_X9);
      while ( __stxr(v5 & ~(1LL << v0), _X9) );
    }
    raw_spin_unlock_bh(g_cam_dma_fence_dev + v1);
    ++v0;
    v1 += 4;
  }
  v17 = g_cam_dma_fence_dev;
  v18 = *(_QWORD ***)(g_cam_dma_fence_dev + 25160);
  if ( v18 )
  {
    v19 = *v18;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v19, 0);
    else
      kvfree(v19);
    v17 = g_cam_dma_fence_dev;
    **(_QWORD **)(g_cam_dma_fence_dev + 25160) = 0;
  }
  v20 = *(_QWORD **)(v17 + 25160);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v20, 0);
  else
    kvfree(v20);
  v21 = g_cam_dma_fence_dev + 25096;
  *(_QWORD *)(g_cam_dma_fence_dev + 25160) = 0;
  result = mutex_unlock(v21);
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             debug_mdl & 0x400000000LL,
             4,
             "cam_dma_fence_close",
             839,
             "Close on Camera DMA fence driver");
  return result;
}
