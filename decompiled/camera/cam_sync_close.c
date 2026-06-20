__int64 __fastcall cam_sync_close(__int64 a1)
{
  __int64 v2; // x24
  _QWORD *v3; // x0
  unsigned int v4; // w20
  int v5; // w8
  __int64 v6; // x26
  __int64 v7; // x27
  bool v8; // cf
  unsigned int v9; // w0
  __int64 v10; // x26
  __int64 v11; // x27
  __int64 i; // x22
  _QWORD *v13; // x0
  _QWORD *v14; // x0
  __int64 v15; // x0

  v2 = *(_QWORD *)(video_devdata() + 336);
  if ( v2 )
  {
    v3 = (_QWORD *)mutex_lock(v2 + 8328);
    v4 = 0;
    v5 = *(_DWORD *)(v2 + 8376) - 1;
    *(_DWORD *)(v2 + 8376) = v5;
    if ( !v5 )
    {
      v6 = -2047;
      v7 = 320;
      do
      {
        if ( *(_DWORD *)(*(_QWORD *)(v2 + 128) + v7) == 1 )
        {
          v9 = cam_sync_signal((int)v6 + 2048, 3u, 7u);
          if ( (v9 & 0x80000000) != 0 )
          {
            v4 = v9;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              128,
              1,
              "cam_sync_close",
              2478,
              "Cleanup signal fail idx:%d",
              v6 + 2048);
          }
          else
          {
            v4 = 0;
          }
        }
        v8 = __CFADD__(v6++, 1);
        v7 += 216;
      }
      while ( !v8 );
      _flush_workqueue(*(_QWORD *)(v2 + 8392));
      v10 = -2047;
      v11 = 320;
      do
      {
        if ( *(_DWORD *)(*(_QWORD *)(v2 + 128) + v11) )
        {
          v4 = cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), (unsigned int)(v10 + 2048), 0, 0);
          if ( (v4 & 0x80000000) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              128,
              1,
              "cam_sync_close",
              2500,
              "Cleanup destroy fail:idx:%d\n",
              v10 + 2048);
        }
        v8 = __CFADD__(v10++, 1);
        v11 += 216;
      }
      while ( !v8 );
      if ( *(_QWORD *)(v2 + 8672) )
      {
        for ( i = 0; i != 128; i += 8 )
        {
          v13 = *(_QWORD **)(*(_QWORD *)(v2 + 8672) + i);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v13, 0);
          else
            kvfree(v13);
          *(_QWORD *)(*(_QWORD *)(v2 + 8672) + i) = 0;
        }
      }
      v14 = *(_QWORD **)(v2 + 8672);
      if ( mem_trace_en == 1 )
        v3 = cam_mem_trace_free(v14, 0);
      else
        v3 = (_QWORD *)kvfree(v14);
      *(_QWORD *)(v2 + 8672) = 0;
    }
    v15 = cam_dma_fence_close(v3);
    cam_synx_obj_close(v15);
    mutex_unlock(v2 + 8328);
    raw_spin_lock_bh(v2 + 8408);
    *(_QWORD *)(v2 + 8400) = 0;
    raw_spin_unlock_bh(v2 + 8408);
    v4l2_fh_release(a1);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_close",
      2455,
      "Sync device NULL");
    return (unsigned int)-19;
  }
  return v4;
}
