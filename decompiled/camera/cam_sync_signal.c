__int64 __fastcall cam_sync_signal(unsigned int a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  int v8; // w0
  unsigned int v9; // w21
  unsigned int v16; // w8
  unsigned int v17; // w8
  int v18; // w8
  unsigned int v19; // w23
  int v20; // w23
  _QWORD *v21; // x10
  _QWORD *v22; // x11
  _QWORD *v23; // [xsp+10h] [xbp-60h] BYREF
  _QWORD **v24; // [xsp+18h] [xbp-58h]
  __int64 v25; // [xsp+20h] [xbp-50h] BYREF
  __int64 v26; // [xsp+28h] [xbp-48h]
  __int64 v27; // [xsp+30h] [xbp-40h]
  __int64 v28; // [xsp+38h] [xbp-38h]
  __int64 v29; // [xsp+40h] [xbp-30h]
  __int64 v30; // [xsp+48h] [xbp-28h] BYREF
  __int64 v31; // [xsp+50h] [xbp-20h]
  __int64 v32; // [xsp+58h] [xbp-18h]
  __int64 v33; // [xsp+60h] [xbp-10h]
  __int64 v34; // [xsp+68h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = nullptr;
  v24 = nullptr;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( a1 - 2048 > 0xFFFFF800 )
  {
    raw_spin_lock_bh(sync_dev + 4LL * a1 + 136);
    v7 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
    v8 = cam_sync_signal_validate_util(a1, a2);
    if ( v8 )
    {
      v9 = v8;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_signal",
        420,
        "Error: Failed to validate signal info for sync_obj = %s[%d] with status = %d rc = %d",
        (const char *)v7,
        a1,
        a2,
        v8);
      cam_sync_dump_monitor_array(v7);
      raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
      result = v9;
      goto LABEL_30;
    }
    _X9 = (unsigned int *)(v7 + 176);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v16 = __ldxr(_X9);
      v17 = v16 - 1;
    }
    while ( __stlxr(v17, _X9) );
    __dmb(0xBu);
    if ( v17 )
    {
      raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
LABEL_29:
      result = 0;
      goto LABEL_30;
    }
    *(_DWORD *)(v7 + 104) = a2;
    if ( (*(_QWORD *)(v7 + 184) & 4) == 0 )
    {
LABEL_20:
      if ( (*(_QWORD *)(v7 + 184) & 8) != 0 )
      {
        LODWORD(v26) = a2;
        HIDWORD(v25) = *(_DWORD *)(v7 + 204);
        v19 = *(_DWORD *)(v7 + 208);
        raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
        v20 = cam_synx_obj_internal_signal(v19, &v25);
        raw_spin_lock_bh(sync_dev + 4LL * a1 + 136);
        if ( v20 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_sync_signal",
            460,
            "Error: Failed to signal associated synx obj = %d for sync_obj = %d",
            HIDWORD(v25),
            a1);
          cam_sync_dump_monitor_array(v7);
        }
      }
      cam_sync_util_dispatch_signaled_cb(a1, a2, a3);
      v23 = &v23;
      v24 = &v23;
      v21 = *(_QWORD **)(v7 + 72);
      if ( v21 != (_QWORD *)(v7 + 72) )
      {
        v22 = *(_QWORD **)(v7 + 80);
        v21[1] = &v23;
        v23 = v21;
        *v22 = &v23;
        v24 = (_QWORD **)v22;
        *(_QWORD *)(v7 + 72) = v7 + 72;
        *(_QWORD *)(v7 + 80) = v7 + 72;
      }
      if ( (cam_sync_monitor_mask & 2) != 0 )
        cam_generic_fence_update_monitor_array(a1, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 4);
      raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
      if ( v23 != &v23 )
        cam_sync_signal_parent_util(a2, a3, &v23);
      goto LABEL_29;
    }
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    HIDWORD(v30) = *(_DWORD *)(v7 + 192);
    if ( a2 != 2 )
    {
      if ( a2 == 3 )
      {
        v18 = -68;
      }
      else
      {
        if ( a2 != 4 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_sync_signal_dma_fence_util",
            306,
            "Signaling undefined status: %d for sync obj: %d",
            a2,
            *(_DWORD *)(v7 + 68));
          goto LABEL_19;
        }
        v18 = -125;
      }
      LODWORD(v31) = v18;
    }
    if ( !(unsigned int)cam_dma_fence_internal_signal(*(unsigned int *)(v7 + 196), &v30) )
      goto LABEL_20;
LABEL_19:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_signal",
      439,
      "Error: Failed to signal associated dma fencefd = %d for sync_obj = %s[%d]",
      *(_DWORD *)(v7 + 192),
      (const char *)v7,
      a1);
    cam_sync_dump_monitor_array(v7);
    goto LABEL_20;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    128,
    1,
    "cam_sync_signal",
    409,
    "Error: Out of range sync obj (0 <= %d < %d)",
    a1,
    2048);
  result = 4294967274LL;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
