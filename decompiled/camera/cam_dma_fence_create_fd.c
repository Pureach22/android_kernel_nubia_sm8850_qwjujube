__int64 __fastcall cam_dma_fence_create_fd(unsigned int *a1, unsigned int *a2, const char *a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  _QWORD *v8; // x22
  __int64 v9; // x0
  __int64 v10; // x23
  unsigned int unused_fd_flags; // w22
  _QWORD *v12; // x0
  int v13; // w24
  __int64 v14; // x3
  unsigned __int64 v23; // x4
  int v25; // w8
  __int64 v27; // x8
  unsigned __int64 v30; // x10
  unsigned int v31; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_dma_fence_create_fd",
      644,
      "Invalid args fd: %pK dma_fence_row_idx: %pK",
      a1,
      a2);
    result = 4294967274LL;
    goto LABEL_38;
  }
  v31 = 0;
  if ( (unsigned int)_cam_dma_fence_find_free_idx(&v31) )
  {
LABEL_37:
    result = 4294967219LL;
    goto LABEL_38;
  }
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(4, 0xCC0u, 0, "__cam_dma_fence_get_fd", 0x250u);
  else
    v6 = _kvmalloc_node_noprof(4, 0, 3520, 0xFFFFFFFFLL);
  v8 = (_QWORD *)v6;
  if ( !v6 )
  {
LABEL_36:
    v27 = 1LL << v31;
    _X9 = (unsigned __int64 *)(g_cam_dma_fence_dev + 25144 + 8 * ((unsigned __int64)v31 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v30 = __ldxr(_X9);
    while ( __stxr(v30 & ~v27, _X9) );
    goto LABEL_37;
  }
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(64, 0xCC0u, 0, "__cam_dma_fence_get_fd", 0x254u);
  else
    v9 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
  v10 = v9;
  if ( !v9 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v8, 0);
    else
      kvfree(v8);
    goto LABEL_36;
  }
  *(_DWORD *)v8 = 0;
  _X8 = &g_cam_dma_fence_seq_no;
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr((unsigned __int64 *)&g_cam_dma_fence_seq_no);
  while ( __stlxr(v23 + 1, (unsigned __int64 *)&g_cam_dma_fence_seq_no) );
  __dmb(0xBu);
  dma_fence_init(v9, &cam_sync_dma_fence_ops, v8);
  unused_fd_flags = get_unused_fd_flags(0x80000);
  if ( (unused_fd_flags & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "__cam_dma_fence_get_fd",
      608,
      "failed to get a unused fd: %d",
      unused_fd_flags);
    _X0 = (unsigned int *)(v10 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v25 = __ldxr(_X0);
    while ( __stlxr(v25 - 1, _X0) );
    if ( v25 != 1 )
    {
LABEL_34:
      if ( v25 <= 0 )
        refcount_warn_saturate();
      goto LABEL_36;
    }
    goto LABEL_21;
  }
  v12 = (_QWORD *)sync_file_create(v10);
  if ( !v12 )
  {
    put_unused_fd(unused_fd_flags);
    _X0 = (unsigned int *)(v10 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v25 = __ldxr(_X0);
    while ( __stlxr(v25 - 1, _X0) );
    if ( v25 != 1 )
      goto LABEL_34;
LABEL_21:
    __dmb(9u);
    dma_fence_release();
    goto LABEL_36;
  }
  fd_install(unused_fd_flags, *v12);
  v13 = v31;
  v14 = v31;
  *a2 = v31;
  _cam_dma_fence_init_row(a3, v10, unused_fd_flags, v14, 0);
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "__cam_dma_fence_get_fd",
      627,
      "Created dma fence fd: %d[%s] seqno: %llu row_idx: %u ref_cnt: %u",
      unused_fd_flags,
      a3,
      *(_QWORD *)(v10 + 40),
      v13,
      *(_DWORD *)(v10 + 56));
  result = 0;
  *a1 = unused_fd_flags;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
