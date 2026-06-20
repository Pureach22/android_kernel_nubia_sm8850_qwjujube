__int64 __fastcall cam_sync_open(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v4; // w19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0

  v2 = *(_QWORD *)(video_devdata() + 336);
  if ( !v2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_open",
      2409,
      "Sync device NULL");
    return 4294967277LL;
  }
  mutex_lock(v2 + 8328);
  if ( *(int *)(v2 + 8376) >= 1 )
  {
    mutex_unlock(v2 + 8328);
    return 4294967182LL;
  }
  v4 = v4l2_fh_open(a1);
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_open",
      2430,
      "v4l2_fh_open failed : %d",
      v4);
  }
  else
  {
    ++*(_DWORD *)(v2 + 8376);
    v5 = cam_synx_obj_open();
    cam_dma_fence_open(v5);
    raw_spin_lock_bh(v2 + 8408);
    *(_QWORD *)(v2 + 8400) = *(_QWORD *)(a1 + 32);
    raw_spin_unlock_bh(v2 + 8408);
  }
  if ( (cam_sync_monitor_mask & 2) != 0 )
  {
    if ( mem_trace_en == 1 )
    {
      v6 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_sync_open", 0x984u);
      *(_QWORD *)(v2 + 8672) = v6;
      if ( !v6 )
        goto LABEL_13;
    }
    else
    {
      v7 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v2 + 8672) = v7;
      if ( !v7 )
LABEL_13:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          2,
          "cam_sync_open",
          2440,
          "Failed to allocate memory %d",
          128);
    }
  }
  mutex_unlock(v2 + 8328);
  return v4;
}
