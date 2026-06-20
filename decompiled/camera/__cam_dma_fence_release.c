__int64 __fastcall _cam_dma_fence_release(unsigned int *_X0)
{
  unsigned int v1; // w19
  __int64 v2; // x21
  _QWORD *v3; // x22
  __int64 v4; // x23
  int v5; // w8
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x10
  unsigned int v9; // w9
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x12
  __int64 v13; // x9
  int v14; // w10
  __int64 v15; // x10
  __int64 v16; // x8
  unsigned int v17; // w19
  __int64 v18; // x10
  unsigned int v19; // w9
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x12
  __int64 v23; // x9
  int v24; // w10
  __int64 v25; // x10
  __int64 v26; // x8
  int v32; // w8
  __int64 v33; // x10
  unsigned __int64 v37; // x10
  __int64 v38; // [xsp+18h] [xbp-48h] BYREF
  __int64 v39; // [xsp+20h] [xbp-40h]
  __int64 v40; // [xsp+28h] [xbp-38h]
  __int64 v41; // [xsp+30h] [xbp-30h]
  __int64 v42; // [xsp+38h] [xbp-28h]
  __int64 v43; // [xsp+40h] [xbp-20h]
  __int64 v44; // [xsp+48h] [xbp-18h]
  __int64 v45; // [xsp+50h] [xbp-10h]
  __int64 v46; // [xsp+58h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)_X0 >= 0x81 )
  {
    __break(0x5512u);
    goto LABEL_45;
  }
  v3 = &unk_394000;
  v2 = (int)_X0;
  v1 = (unsigned int)_X0;
  raw_spin_lock_bh(g_cam_dma_fence_dev + 4LL * (int)_X0 + 24584);
  v4 = g_cam_dma_fence_dev + 192LL * (int)v2;
  v5 = *(_DWORD *)(v4 + 148);
  v6 = *(_QWORD *)(v4 + 136);
  if ( v5 == 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      2,
      "__cam_dma_fence_release",
      701,
      "Unsignaled fence being released name: %s seqno: %llu fd: %d",
      (const char *)(v4 + 8),
      *(_QWORD *)(v6 + 40),
      *(_DWORD *)(v4 + 144));
    if ( (cam_sync_monitor_mask & 4) != 0 )
      cam_generic_fence_update_monitor_array(
        v1,
        g_cam_dma_fence_dev + 25096,
        *(_QWORD *)(g_cam_dma_fence_dev + 25160),
        4);
    goto LABEL_19;
  }
  if ( v5 )
  {
LABEL_19:
    if ( (*(_BYTE *)(v4 + 193) & 1) == 0
      && !(unsigned int)_cam_dma_fence_signal_fence((_QWORD *)v6, 0xFFFFFF83)
      && *(_DWORD *)(v4 + 148) == 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000000LL,
        2,
        "__cam_dma_fence_release",
        716,
        "Unsignaled fence being released name: %s seqno: %llu fd: %d, row was marked as signaled",
        (const char *)(v4 + 8),
        *(_QWORD *)(v6 + 40),
        *(_DWORD *)(v4 + 144));
    }
    if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000000LL,
        4,
        "__cam_dma_fence_release",
        721,
        "Releasing dma fence with fd: %d[%s] row_idx: %u current ref_cnt: %u",
        *(_DWORD *)(v4 + 144),
        (const char *)(v4 + 8),
        v1,
        *(_DWORD *)(v6 + 56));
    if ( (cam_sync_monitor_mask & 4) != 0 )
    {
      cam_generic_fence_update_monitor_array(
        v1,
        g_cam_dma_fence_dev + 25096,
        *(_QWORD *)(g_cam_dma_fence_dev + 25160),
        7);
      if ( (cam_sync_monitor_mask & 0x40000) != 0 )
      {
        v18 = *(_QWORD *)(g_cam_dma_fence_dev + 25160);
        if ( v18 )
        {
          if ( (cam_sync_monitor_mask & 4) != 0 )
          {
            v41 = 0;
            v42 = 0;
            v19 = v1 == 128 ? 0 : v1;
            v39 = 0;
            v40 = 0;
            v20 = *(_QWORD *)(v18 + 8LL * (v1 == 128));
            if ( *(_DWORD *)(v20 + 1616LL * v19 + 140) )
            {
              v21 = g_cam_dma_fence_dev + 192LL * v1;
              v22 = *(_QWORD *)(v21 + 136);
              v38 = v21 + 8;
              HIDWORD(v39) = *(_DWORD *)(v21 + 144);
              v23 = v20 + 1616LL * v19;
              HIDWORD(v40) = *(_DWORD *)(v21 + 148);
              v24 = *(_DWORD *)(v22 + 56);
              v43 = v23;
              HIDWORD(v41) = v24;
              LODWORD(v42) = 2;
              v25 = 176;
              LODWORD(v40) = *(_DWORD *)(v21 + 176);
              if ( *(_BYTE *)(v23 + 168) )
                v26 = 896;
              else
                v26 = 176;
              if ( !*(_BYTE *)(v23 + 168) )
                v25 = 896;
              v44 = v23 + v26;
              v45 = v23 + v25;
              cam_generic_fence_dump_monitor_array((__int64)&v38);
            }
          }
        }
      }
      ((void (__fastcall *)(_QWORD))_cam_dma_fence_save_previous_monitor_data)(v1);
    }
    if ( !v6 )
      goto LABEL_50;
    _X0 = (unsigned int *)(v6 + 56);
LABEL_45:
    __asm { PRFM            #0x11, [X0] }
    do
      v32 = __ldxr(_X0);
    while ( __stlxr(v32 - 1, _X0) );
    if ( v32 == 1 )
    {
      __dmb(9u);
      dma_fence_release();
    }
    else if ( v32 <= 0 )
    {
      refcount_warn_saturate();
    }
LABEL_50:
    *(_QWORD *)(v4 + 8) = 0;
    *(_QWORD *)(v4 + 16) = 0;
    v33 = v3[39];
    *(_QWORD *)(v4 + 184) = 0;
    *(_QWORD *)(v4 + 192) = 0;
    *(_QWORD *)(v4 + 168) = 0;
    *(_QWORD *)(v4 + 176) = 0;
    *(_QWORD *)(v4 + 152) = 0;
    *(_QWORD *)(v4 + 160) = 0;
    *(_QWORD *)(v4 + 136) = 0;
    *(_QWORD *)(v4 + 144) = 0;
    *(_QWORD *)(v4 + 120) = 0;
    *(_QWORD *)(v4 + 128) = 0;
    *(_QWORD *)(v4 + 104) = 0;
    *(_QWORD *)(v4 + 112) = 0;
    *(_QWORD *)(v4 + 88) = 0;
    *(_QWORD *)(v4 + 96) = 0;
    *(_QWORD *)(v4 + 72) = 0;
    *(_QWORD *)(v4 + 80) = 0;
    *(_QWORD *)(v4 + 56) = 0;
    *(_QWORD *)(v4 + 64) = 0;
    *(_QWORD *)(v4 + 40) = 0;
    *(_QWORD *)(v4 + 48) = 0;
    *(_QWORD *)(v4 + 24) = 0;
    *(_QWORD *)(v4 + 32) = 0;
    _X9 = (unsigned __int64 *)(v33 + 25144 + 8LL * (v1 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v37 = __ldxr(_X9);
    while ( __stxr(v37 & ~(1LL << v1), _X9) );
    v7 = v3[39];
    v17 = 0;
    goto LABEL_51;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000000LL,
    1,
    "__cam_dma_fence_release",
    693,
    "Invalid row index: %u, state: %u",
    v1,
    0);
  v7 = g_cam_dma_fence_dev;
  v8 = *(_QWORD *)(g_cam_dma_fence_dev + 25160);
  if ( v8 && (cam_sync_monitor_mask & 4) != 0 )
  {
    v41 = 0;
    v42 = 0;
    v9 = v1 == 128 ? 0 : v1;
    v39 = 0;
    v40 = 0;
    v10 = *(_QWORD *)(v8 + 8LL * (v1 == 128));
    if ( *(_DWORD *)(v10 + 1616LL * v9 + 140) )
    {
      v11 = g_cam_dma_fence_dev + 192LL * v1;
      v12 = *(_QWORD *)(v11 + 136);
      v38 = v11 + 8;
      HIDWORD(v39) = *(_DWORD *)(v11 + 144);
      v13 = v10 + 1616LL * v9;
      HIDWORD(v40) = *(_DWORD *)(v11 + 148);
      v14 = *(_DWORD *)(v12 + 56);
      v43 = v13;
      HIDWORD(v41) = v14;
      LODWORD(v42) = 2;
      v15 = 176;
      LODWORD(v40) = *(_DWORD *)(v11 + 176);
      if ( *(_BYTE *)(v13 + 168) )
        v16 = 896;
      else
        v16 = 176;
      if ( !*(_BYTE *)(v13 + 168) )
        v15 = 896;
      v44 = v13 + v16;
      v45 = v13 + v15;
      cam_generic_fence_dump_monitor_array((__int64)&v38);
      v7 = g_cam_dma_fence_dev;
    }
  }
  v17 = -22;
LABEL_51:
  raw_spin_unlock_bh(v7 + 4 * v2 + 24584);
  _ReadStatusReg(SP_EL0);
  return v17;
}
