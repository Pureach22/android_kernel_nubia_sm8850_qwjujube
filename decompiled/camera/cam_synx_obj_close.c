__int64 cam_synx_obj_close()
{
  __int64 v0; // x26
  __int64 i; // x19
  unsigned __int64 v8; // x10
  __int64 v9; // x25
  __int64 v10; // x22
  unsigned int v11; // w8
  __int64 v12; // x0
  __int64 v13; // x10
  __int64 v14; // x8
  _QWORD **v15; // x9
  _QWORD *v16; // x0
  __int64 v17; // x8
  _QWORD *v18; // x0
  _QWORD *v19; // x0
  __int64 v20; // x0
  __int64 result; // x0
  _QWORD v22[6]; // [xsp+0h] [xbp-30h] BYREF

  v22[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(g_cam_synx_obj_dev + 23560);
  v0 = 0;
  for ( i = 0; i != 256; ++i )
  {
    v9 = g_cam_synx_obj_dev;
    v10 = g_cam_synx_obj_dev + v0;
    if ( *(_DWORD *)(g_cam_synx_obj_dev + v0 + 68) )
    {
      if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000000000LL,
          4,
          "cam_synx_obj_close",
          810,
          "Releasing synx_obj: %d[%s]",
          *(_DWORD *)(g_cam_synx_obj_dev + v0 + 64),
          (const char *)(g_cam_synx_obj_dev + v0));
      if ( *(_BYTE *)(v9 + v0 + 80) == 1 )
      {
        if ( (cam_sync_monitor_mask & 8) != 0 )
          cam_generic_fence_update_monitor_array((unsigned int)i, 0, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 6);
        v11 = *(_DWORD *)(v9 + v0 + 64);
        v22[3] = 0;
        v22[4] = 0;
        v12 = *(_QWORD *)(g_cam_synx_obj_dev + 23552);
        v22[1] = _cam_synx_obj_signal_cb;
        v22[2] = v9 + v0;
        v22[0] = v11;
        synx_cancel_async_wait(v12, v22);
      }
      if ( *(_DWORD *)(v10 + 68) != 2 )
      {
        if ( (cam_sync_monitor_mask & 8) != 0 )
          cam_generic_fence_update_monitor_array((unsigned int)i, 0, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 4);
        synx_signal(*(_QWORD *)(g_cam_synx_obj_dev + 23552), *(unsigned int *)(v9 + v0 + 64), 4);
      }
      if ( (cam_sync_monitor_mask & 8) != 0 )
        cam_generic_fence_update_monitor_array((unsigned int)i, 0, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 7);
      synx_release(*(_QWORD *)(g_cam_synx_obj_dev + 23552), *(unsigned int *)(v9 + v0 + 64));
      *(_QWORD *)v10 = 0;
      *(_QWORD *)(v10 + 8) = 0;
      v13 = g_cam_synx_obj_dev;
      *(_QWORD *)(v10 + 16) = 0;
      *(_QWORD *)(v10 + 24) = 0;
      *(_QWORD *)(v10 + 32) = 0;
      *(_QWORD *)(v10 + 40) = 0;
      *(_QWORD *)(v10 + 48) = 0;
      *(_QWORD *)(v10 + 56) = 0;
      *(_QWORD *)(v10 + 64) = 0;
      *(_QWORD *)(v10 + 72) = 0;
      *(_QWORD *)(v10 + 80) = 0;
      _X9 = (unsigned __int64 *)(v13 + 23608 + 8LL * ((unsigned int)i >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v8 = __ldxr(_X9);
      while ( __stxr(v8 & ~(1LL << i), _X9) );
    }
    v0 += 88;
  }
  v14 = g_cam_synx_obj_dev;
  v15 = *(_QWORD ***)(g_cam_synx_obj_dev + 23640);
  if ( v15 )
  {
    v16 = *v15;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v16, 0);
    else
      kvfree(v16);
    v17 = g_cam_synx_obj_dev;
    **(_QWORD **)(g_cam_synx_obj_dev + 23640) = 0;
    v18 = *(_QWORD **)(*(_QWORD *)(v17 + 23640) + 8LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v18, 0);
    else
      kvfree(v18);
    v14 = g_cam_synx_obj_dev;
    *(_QWORD *)(*(_QWORD *)(g_cam_synx_obj_dev + 23640) + 8LL) = 0;
  }
  v19 = *(_QWORD **)(v14 + 23640);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v19, 0);
  else
    kvfree(v19);
  v20 = g_cam_synx_obj_dev + 23560;
  *(_QWORD *)(g_cam_synx_obj_dev + 23640) = 0;
  result = mutex_unlock(v20);
  if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               debug_mdl & 0x1000000000LL,
               4,
               "cam_synx_obj_close",
               858,
               "Close on Camera SYNX driver");
  _ReadStatusReg(SP_EL0);
  return result;
}
