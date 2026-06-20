__int64 __fastcall cam_dma_fence_get_put_ref(char a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v9; // x8
  __int64 *v10; // x9
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x11
  __int64 v14; // x9
  int v15; // w10
  __int64 v16; // x10
  __int64 v17; // x8
  unsigned int v24; // w8
  int v26; // w8
  const char *v27; // x7
  __int64 v28; // [xsp+8h] [xbp-48h] BYREF
  __int64 v29; // [xsp+10h] [xbp-40h]
  __int64 v30; // [xsp+18h] [xbp-38h]
  __int64 v31; // [xsp+20h] [xbp-30h]
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  __int64 v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0x80 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_get_put_ref",
      271,
      "dma fence idx: %d is invalid",
      a2);
    result = 4294967274LL;
    goto LABEL_31;
  }
  v5 = a2;
  raw_spin_lock_bh(g_cam_dma_fence_dev + 4LL * a2 + 24584);
  v6 = g_cam_dma_fence_dev + 192LL * a2;
  if ( *(_DWORD *)(v6 + 148) )
  {
    v7 = *(_QWORD *)(v6 + 136);
    if ( (a1 & 1) != 0 )
    {
      if ( v7 )
      {
        _X0 = (unsigned int *)(v7 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v24 = __ldxr(_X0);
        while ( __stxr(v24 + 1, _X0) );
        if ( !v24 || (((v24 + 1) | v24) & 0x80000000) != 0 )
          goto LABEL_28;
      }
    }
    else if ( v7 )
    {
      _X0 = (unsigned int *)(v7 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v26 = __ldxr(_X0);
      while ( __stlxr(v26 - 1, _X0) );
      if ( v26 == 1 )
      {
        __dmb(9u);
        dma_fence_release();
      }
      else if ( v26 <= 0 )
      {
LABEL_28:
        refcount_warn_saturate();
      }
    }
    raw_spin_unlock_bh(g_cam_dma_fence_dev + 4 * v5 + 24584);
    result = 0;
    if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    {
      if ( (a1 & 1) != 0 )
        v27 = "getref";
      else
        v27 = "putref";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000000LL,
        4,
        "cam_dma_fence_get_put_ref",
        297,
        "Refcnt: %u after %s for dma fence with seqno: %llu",
        *(_DWORD *)(v7 + 56),
        v27,
        *(_QWORD *)(v7 + 40));
      result = 0;
    }
    goto LABEL_31;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000000LL,
    1,
    "cam_dma_fence_get_put_ref",
    281,
    "dma fence at idx: %d is in invalid state: %d",
    a2,
    0);
  v9 = g_cam_dma_fence_dev;
  v10 = *(__int64 **)(g_cam_dma_fence_dev + 25160);
  if ( v10 )
  {
    if ( (cam_sync_monitor_mask & 4) != 0 )
    {
      v31 = 0;
      v32 = 0;
      v29 = 0;
      v30 = 0;
      v11 = *v10;
      if ( *(_DWORD *)(v11 + 1616LL * (unsigned int)v5 + 140) )
      {
        v12 = g_cam_dma_fence_dev + 192LL * (unsigned int)v5;
        v13 = *(_QWORD *)(v12 + 136);
        v28 = v12 + 8;
        HIDWORD(v29) = *(_DWORD *)(v12 + 144);
        v14 = v11 + 1616LL * (unsigned int)v5;
        HIDWORD(v30) = *(_DWORD *)(v12 + 148);
        v15 = *(_DWORD *)(v13 + 56);
        v33 = v14;
        HIDWORD(v31) = v15;
        LODWORD(v32) = 2;
        v16 = 176;
        LODWORD(v30) = *(_DWORD *)(v12 + 176);
        if ( *(_BYTE *)(v14 + 168) )
          v17 = 896;
        else
          v17 = 176;
        if ( !*(_BYTE *)(v14 + 168) )
          v16 = 896;
        v34 = v14 + v17;
        v35 = v14 + v16;
        cam_generic_fence_dump_monitor_array((__int64)&v28);
        v9 = g_cam_dma_fence_dev;
      }
    }
  }
  raw_spin_unlock_bh(v9 + 4LL * a2 + 24584);
  result = 4294967274LL;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
