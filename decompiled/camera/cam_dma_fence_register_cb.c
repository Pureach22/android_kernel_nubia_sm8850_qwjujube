__int64 __fastcall cam_dma_fence_register_cb(_DWORD *a1, unsigned int *a2, const void *a3)
{
  __int64 v5; // x19
  __int64 result; // x0
  __int64 v7; // x10
  int v8; // w9
  __int64 v9; // x20
  __int64 v10; // x25
  unsigned int v11; // w20
  unsigned int v12; // w0
  __int64 v13; // x7
  __int64 v14; // x8
  __int64 *v15; // x9
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x11
  __int64 v19; // x9
  int v20; // w10
  __int64 v21; // x10
  __int64 v22; // x8
  int v23; // w8
  __int64 v24; // [xsp+18h] [xbp-48h] BYREF
  __int64 v25; // [xsp+20h] [xbp-40h]
  __int64 v26; // [xsp+28h] [xbp-38h]
  __int64 v27; // [xsp+30h] [xbp-30h]
  __int64 v28; // [xsp+38h] [xbp-28h]
  __int64 v29; // [xsp+40h] [xbp-20h]
  __int64 v30; // [xsp+48h] [xbp-18h]
  __int64 v31; // [xsp+50h] [xbp-10h]
  __int64 v32; // [xsp+58h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_register_cb",
      384,
      "Invalid args sync_obj: %p dma_fence_idx: %p sync_cb: %p",
      a1,
      a2,
      a3);
    result = 4294967274LL;
    goto LABEL_27;
  }
  v5 = *a2;
  if ( (unsigned int)v5 >= 0x80 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_register_cb",
      392,
      "dma fence idx: %d is invalid",
      v5);
    result = 4294967274LL;
    goto LABEL_27;
  }
  raw_spin_lock_bh(g_cam_dma_fence_dev + 4 * v5 + 24584);
  v7 = g_cam_dma_fence_dev + 192LL * (unsigned int)v5;
  v8 = *(_DWORD *)(v7 + 148);
  v9 = *(_QWORD *)(v7 + 136);
  v10 = v7 + 8;
  if ( v8 != 1 )
  {
    if ( (cam_sync_monitor_mask & 4) != 0 )
    {
      cam_generic_fence_update_monitor_array(
        (unsigned int)v5,
        g_cam_dma_fence_dev + 25096,
        *(_QWORD *)(g_cam_dma_fence_dev + 25160),
        2);
      v8 = *(_DWORD *)(v10 + 140);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_register_cb",
      409,
      "dma fence at idx: %d fd: %d seqno: %llu is not active, current state: %d",
      v5,
      *(_DWORD *)(v10 + 136),
      *(_QWORD *)(v9 + 40),
      v8);
    v11 = -22;
    goto LABEL_17;
  }
  if ( *(_BYTE *)(v7 + 192) == 1 )
  {
    if ( (cam_sync_monitor_mask & 4) != 0 )
      cam_generic_fence_update_monitor_array(
        (unsigned int)v5,
        g_cam_dma_fence_dev + 25096,
        *(_QWORD *)(g_cam_dma_fence_dev + 25160),
        3);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      2,
      "cam_dma_fence_register_cb",
      428,
      "dma fence at idx: %d fd: %d seqno: %llu has already registered a cb for sync: %d - same fd for 2 fences?",
      v5,
      *(_DWORD *)(v10 + 136),
      *(_QWORD *)(v9 + 40),
      *(_DWORD *)(v10 + 168));
    v11 = 0;
    goto LABEL_17;
  }
  v12 = dma_fence_add_callback(*(_QWORD *)(v7 + 136), v7 + 152, _cam_dma_fence_signal_cb);
  if ( v12 )
  {
    v13 = *(_QWORD *)(v9 + 40);
    v11 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_register_cb",
      437,
      "Failed to register cb for dma fence fd: %d seqno: %llu rc: %d",
      *(_DWORD *)(v10 + 136),
      v13,
      v12);
LABEL_17:
    v14 = g_cam_dma_fence_dev;
    v15 = *(__int64 **)(g_cam_dma_fence_dev + 25160);
    if ( v15 )
    {
      if ( (cam_sync_monitor_mask & 4) != 0 )
      {
        v27 = 0;
        v28 = 0;
        v25 = 0;
        v26 = 0;
        v16 = *v15;
        if ( *(_DWORD *)(v16 + 1616LL * (unsigned int)v5 + 140) )
        {
          v17 = g_cam_dma_fence_dev + 192LL * (unsigned int)v5;
          v18 = *(_QWORD *)(v17 + 136);
          v24 = v17 + 8;
          HIDWORD(v25) = *(_DWORD *)(v17 + 144);
          v19 = v16 + 1616LL * (unsigned int)v5;
          HIDWORD(v26) = *(_DWORD *)(v17 + 148);
          v20 = *(_DWORD *)(v18 + 56);
          v29 = v19;
          HIDWORD(v27) = v20;
          LODWORD(v28) = 2;
          v21 = 176;
          LODWORD(v26) = *(_DWORD *)(v17 + 176);
          if ( *(_BYTE *)(v19 + 168) )
            v22 = 896;
          else
            v22 = 176;
          if ( !*(_BYTE *)(v19 + 168) )
            v21 = 896;
          v30 = v19 + v22;
          v31 = v19 + v21;
          cam_generic_fence_dump_monitor_array((__int64)&v24);
          v14 = g_cam_dma_fence_dev;
        }
      }
    }
    raw_spin_unlock_bh(v14 + 4 * v5 + 24584);
    result = v11;
    goto LABEL_27;
  }
  if ( (cam_sync_monitor_mask & 4) != 0 )
    cam_generic_fence_update_monitor_array(
      (unsigned int)v5,
      g_cam_dma_fence_dev + 25096,
      *(_QWORD *)(g_cam_dma_fence_dev + 25160),
      1);
  *(_BYTE *)(v10 + 184) = 1;
  v23 = *a1;
  *(_QWORD *)(v10 + 176) = a3;
  *(_DWORD *)(v10 + 168) = v23;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "cam_dma_fence_register_cb",
      452,
      "CB successfully registered for dma fence fd: %d seqno: %llu for sync_obj: %d",
      *(_DWORD *)(v10 + 136),
      *(_QWORD *)(v9 + 40),
      *a1);
  raw_spin_unlock_bh(g_cam_dma_fence_dev + 4 * v5 + 24584);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
