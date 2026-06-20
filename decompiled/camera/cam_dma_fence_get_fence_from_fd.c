unsigned __int64 __fastcall cam_dma_fence_get_fence_from_fd(unsigned int a1, unsigned int *a2)
{
  __int64 v4; // x20
  __int64 v5; // x23
  __int64 v6; // x24
  __int64 v7; // x8
  unsigned __int64 v8; // x20
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned __int64 fence; // x0
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  unsigned int v16; // w22
  __int64 v17; // x7
  int v18; // w9
  const char *v19; // x3
  const char *v20; // x5
  __int64 v21; // x1
  __int64 v22; // x4
  __int64 v23; // x8
  int v25; // w8
  unsigned int v32; // w8
  unsigned int v33; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+18h] [xbp-8h]

  v4 = 0;
  v5 = 0;
  v6 = 24584;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    raw_spin_lock_bh(g_cam_dma_fence_dev + v6);
    v7 = g_cam_dma_fence_dev;
    if ( *(_DWORD *)(g_cam_dma_fence_dev + v4 + 148) )
    {
      if ( *(_DWORD *)(g_cam_dma_fence_dev + v4 + 144) == a1 )
        break;
    }
    raw_spin_unlock_bh(g_cam_dma_fence_dev + v6);
    ++v5;
    v6 += 4;
    v4 += 192;
    if ( v5 == 128 )
      goto LABEL_14;
  }
  *a2 = v5;
  v8 = *(_QWORD *)(v7 + v4 + 136);
  _X0 = (unsigned int *)raw_spin_unlock_bh(v7 + v6);
  if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = *a2;
    if ( (unsigned int)v10 >= 0x81 )
      goto LABEL_33;
    _X0 = (unsigned int *)raw_spin_lock_bh(g_cam_dma_fence_dev + 4 * v10 + 24584);
    if ( *a2 > 0x80 )
      goto LABEL_33;
    v11 = g_cam_dma_fence_dev + 192LL * *a2;
    if ( !*(_DWORD *)(v11 + 148) || *(_DWORD *)(v11 + 144) != a1 || *(_QWORD *)(v11 + 136) != v8 )
    {
      _X0 = (unsigned int *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned int *))cam_print_log)(
                              3,
                              0x400000000LL,
                              1,
                              "cam_dma_fence_get_fence_from_fd",
                              360,
                              "dma fence at idx: %d is in invalid state: %d",
                              a2);
      v12 = *a2;
      if ( (unsigned int)v12 <= 0x80 )
      {
        raw_spin_unlock_bh(g_cam_dma_fence_dev + 4 * v12 + 24584);
        v8 = -22;
        goto LABEL_40;
      }
      goto LABEL_33;
    }
    _X0 = (unsigned int *)(v8 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v32 = __ldxr(_X0);
    while ( __stxr(v32 + 1, _X0) );
    if ( !v32 || (((v32 + 1) | v32) & 0x80000000) != 0 )
      _X0 = (unsigned int *)refcount_warn_saturate();
    v23 = *a2;
    if ( (unsigned int)v23 > 0x80 )
    {
LABEL_33:
      __break(0x5512u);
LABEL_34:
      __asm { PRFM            #0x11, [X0] }
      do
        v25 = __ldxr(_X0);
      while ( __stlxr(v25 - 1, _X0) );
      if ( v25 == 1 )
      {
        __dmb(9u);
        dma_fence_release();
      }
      else if ( v25 <= 0 )
      {
        refcount_warn_saturate();
      }
      v8 = 0;
      goto LABEL_40;
    }
    raw_spin_unlock_bh(g_cam_dma_fence_dev + 4 * v23 + 24584);
    if ( (debug_mdl & 0x400000000LL) == 0 || debug_priority )
      goto LABEL_40;
    v17 = *(_QWORD *)(v8 + 40);
    v18 = *(_DWORD *)(v8 + 56);
    v19 = "cam_dma_fence_get_fence_from_fd";
    v20 = "dma fence found for fd: %d with seqno: %llu ref_cnt: %u";
    v21 = debug_mdl & 0x400000000LL;
    v22 = 369;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
      3,
      v21,
      4,
      v19,
      v22,
      v20,
      a1,
      v17,
      v18);
    goto LABEL_40;
  }
LABEL_14:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000000LL,
    2,
    "cam_dma_fence_get_fence_from_fd",
    348,
    "dma fence with fd: %d is an external fence, querying sync file",
    a1);
  fence = sync_file_get_fence(a1);
  if ( !fence || (v8 = fence, fence >= 0xFFFFFFFFFFFFF001LL) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_get_fence_from_sync_file",
      315,
      "Invalid fd: %d no dma fence found",
      a1);
    v8 = -22;
    goto LABEL_40;
  }
  v33 = 0;
  if ( (unsigned int)_cam_dma_fence_find_free_idx(&v33) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_get_fence_from_sync_file",
      320,
      "No free idx");
    _X0 = (unsigned int *)(v8 + 56);
    goto LABEL_34;
  }
  v14 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v8 + 8) + 8LL);
  if ( *((_DWORD *)v14 - 1) != -352706110 )
    __break(0x8228u);
  v15 = v14(v8);
  v16 = v33;
  _cam_dma_fence_init_row(v15, v8, a1, v33, 1);
  *a2 = v16;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
  {
    v17 = *(_QWORD *)(v8 + 40);
    v18 = *(_DWORD *)(v8 + 56);
    v19 = "cam_dma_fence_get_fence_from_sync_file";
    v20 = "External dma fence with fd: %d seqno: %llu ref_cnt: %u updated in tbl";
    v21 = debug_mdl & 0x400000000LL;
    v22 = 329;
    goto LABEL_25;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v8;
}
