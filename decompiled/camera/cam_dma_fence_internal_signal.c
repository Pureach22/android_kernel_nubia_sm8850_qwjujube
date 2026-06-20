__int64 __fastcall cam_dma_fence_internal_signal(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned __int64 v8; // x21
  __int64 v9; // x25
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x11
  __int64 v15; // x9
  int v16; // w10
  __int64 v17; // x10
  __int64 v18; // x8
  int v20; // w22
  __int64 v21; // [xsp+18h] [xbp-48h] BYREF
  __int64 v22; // [xsp+20h] [xbp-40h]
  __int64 v23; // [xsp+28h] [xbp-38h]
  __int64 v24; // [xsp+30h] [xbp-30h]
  __int64 v25; // [xsp+38h] [xbp-28h]
  __int64 v26; // [xsp+40h] [xbp-20h]
  __int64 v27; // [xsp+48h] [xbp-18h]
  __int64 v28; // [xsp+50h] [xbp-10h]
  __int64 v29; // [xsp+58h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x80 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_internal_signal",
      500,
      "dma fence idx: %d is invalid",
      a1);
    v3 = -22;
    goto LABEL_19;
  }
  v5 = a1;
  raw_spin_lock_bh(g_cam_dma_fence_dev + 4LL * a1 + 24584);
  v6 = g_cam_dma_fence_dev;
  v7 = g_cam_dma_fence_dev + 192LL * a1;
  v8 = *(_QWORD *)(v7 + 136);
  *(_BYTE *)(v7 + 194) = 1;
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_internal_signal",
      513,
      "DMA fence in row: %d is invalid",
      a1);
LABEL_8:
    v3 = -22;
LABEL_9:
    v10 = g_cam_dma_fence_dev;
    v11 = *(__int64 **)(g_cam_dma_fence_dev + 25160);
    if ( v11 )
    {
      if ( (cam_sync_monitor_mask & 4) != 0 )
      {
        v24 = 0;
        v25 = 0;
        v22 = 0;
        v23 = 0;
        v12 = *v11;
        if ( *(_DWORD *)(v12 + 1616LL * (unsigned int)v5 + 140) )
        {
          v13 = g_cam_dma_fence_dev + 192LL * (unsigned int)v5;
          v14 = *(_QWORD *)(v13 + 136);
          v21 = v13 + 8;
          HIDWORD(v22) = *(_DWORD *)(v13 + 144);
          v15 = v12 + 1616LL * (unsigned int)v5;
          HIDWORD(v23) = *(_DWORD *)(v13 + 148);
          v16 = *(_DWORD *)(v14 + 56);
          v26 = v15;
          HIDWORD(v24) = v16;
          LODWORD(v25) = 2;
          v17 = 176;
          LODWORD(v23) = *(_DWORD *)(v13 + 176);
          if ( *(_BYTE *)(v15 + 168) )
            v18 = 896;
          else
            v18 = 176;
          if ( !*(_BYTE *)(v15 + 168) )
            v17 = 896;
          v27 = v15 + v18;
          v28 = v15 + v17;
          cam_generic_fence_dump_monitor_array((__int64)&v21);
          v10 = g_cam_dma_fence_dev;
        }
      }
    }
    raw_spin_unlock_bh(v10 + 4 * v5 + 24584);
    goto LABEL_19;
  }
  v9 = v7 + 8;
  if ( *(_DWORD *)(v7 + 148) == 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      2,
      "cam_dma_fence_internal_signal",
      521,
      "dma fence fd: %d[seqno: %llu] already in signaled state",
      *(_DWORD *)(a2 + 4),
      *(_QWORD *)(v8 + 40));
    v3 = 0;
    goto LABEL_9;
  }
  if ( (cam_sync_monitor_mask & 4) != 0 )
    cam_generic_fence_update_monitor_array(a1, v6 + 25096, *(_QWORD *)(v6 + 25160), 4);
  if ( *(_BYTE *)(v9 + 184) == 1 && (dma_fence_remove_callback(*(_QWORD *)(v9 + 128), v9 + 144) & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_internal_signal",
      535,
      "Failed to remove cb for dma fence seqno: %llu fd: %d",
      *(_QWORD *)(v8 + 40),
      *(_DWORD *)(v9 + 136));
    goto LABEL_8;
  }
  v20 = _cam_dma_fence_signal_fence(v8, *(unsigned int *)(a2 + 8));
  if ( v20 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      2,
      "cam_dma_fence_internal_signal",
      545,
      "dma fence seqno: %llu fd: %d already signaled rc: %d",
      *(_QWORD *)(v8 + 40),
      *(_DWORD *)(v9 + 136),
      v20);
  *(_DWORD *)(v9 + 140) = 2;
  raw_spin_unlock_bh(g_cam_dma_fence_dev + 4LL * a1 + 24584);
  v3 = 0;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "cam_dma_fence_internal_signal",
      553,
      "dma fence fd: %d[seqno: %llu] signaled with status: %d rc: %d",
      *(_DWORD *)(a2 + 4),
      *(_QWORD *)(v8 + 40),
      *(_DWORD *)(a2 + 8),
      v20);
    v3 = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v3;
}
