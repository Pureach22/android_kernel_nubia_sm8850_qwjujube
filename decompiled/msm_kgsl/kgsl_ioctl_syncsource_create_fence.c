__int64 __fastcall kgsl_ioctl_syncsource_create_fence(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v5; // x0
  _QWORD *v7; // x20
  __int64 v8; // x0
  __int64 v9; // x0
  _QWORD *v10; // x21
  unsigned int unused_fd_flags; // w22
  __int64 v12; // x0
  _QWORD *v13; // x8
  __int64 v14; // x2
  _QWORD *v15; // x1
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v20; // x19
  int v27; // w9
  int v29; // w8
  int v31; // w8

  v5 = kgsl_syncsource_get(*(_QWORD *)(a1 + 8), *a3);
  if ( !v5 )
    return -22;
  _X19 = v5;
  v7 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v7 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v29 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v29 - 1, (unsigned int *)_X19) );
    if ( v29 == 1 )
    {
      __dmb(9u);
      kgsl_process_private_put(*(unsigned int **)(_X19 + 40));
      kfree(_X19);
    }
    else if ( v29 <= 0 )
    {
      _X0 = (unsigned int *)_X19;
LABEL_34:
      refcount_warn_saturate(_X0, 3);
    }
    return -12;
  }
  v7[8] = _X19;
  v8 = dma_fence_context_alloc(1);
  dma_fence_init(v7, &kgsl_syncsource_fence_ops, _X19 + 64, v8, 1);
  v9 = sync_file_create(v7);
  if ( !v9 )
  {
    dev_err(**(_QWORD **)a1, "Create sync_file failed\n");
    _X0 = (unsigned int *)(v7 + 7);
    __asm { PRFM            #0x11, [X0] }
    do
      v31 = __ldxr(_X0);
    while ( __stlxr(v31 - 1, _X0) );
    if ( v31 != 1 )
    {
      if ( v31 > 0 )
        return -12;
      goto LABEL_34;
    }
    __dmb(9u);
    dma_fence_release(_X0);
    return -12;
  }
  v10 = (_QWORD *)v9;
  unused_fd_flags = get_unused_fd_flags(0);
  if ( (unused_fd_flags & 0x80000000) != 0 )
  {
    v17 = -9;
  }
  else
  {
    fd_install(unused_fd_flags, *v10);
    a3[1] = unused_fd_flags;
    v12 = raw_spin_lock_irqsave(_X19 + 64);
    v13 = v7 + 9;
    v14 = _X19 + 48;
    v15 = *(_QWORD **)(_X19 + 56);
    v16 = v12;
    if ( v7 + 9 == (_QWORD *)(_X19 + 48) || v15 == v13 || *v15 != v14 )
    {
      _list_add_valid_or_report(v7 + 9, v15);
    }
    else
    {
      *(_QWORD *)(_X19 + 56) = v13;
      v7[9] = v14;
      v7[10] = v15;
      *v15 = v13;
    }
    raw_spin_unlock_irqrestore(_X19 + 64, v16);
    v17 = 0;
  }
  _X0 = (unsigned int *)(v7 + 7);
  __asm { PRFM            #0x11, [X0] }
  do
    v27 = __ldxr(_X0);
  while ( __stlxr(v27 - 1, _X0) );
  v20 = v17;
  if ( v27 == 1 )
  {
    __dmb(9u);
    dma_fence_release(_X0);
    if ( (unused_fd_flags & 0x80000000) == 0 )
      return v20;
  }
  else if ( v27 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
    if ( (unused_fd_flags & 0x80000000) == 0 )
      return v20;
  }
  else if ( (unused_fd_flags & 0x80000000) == 0 )
  {
    return v20;
  }
  fput(*v10);
  return v20;
}
