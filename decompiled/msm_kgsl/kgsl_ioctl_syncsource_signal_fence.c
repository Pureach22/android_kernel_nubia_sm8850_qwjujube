__int64 __fastcall kgsl_ioctl_syncsource_signal_fence(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int *v4; // x0
  __int64 fence; // x0
  __int64 v7; // x21
  __int64 v8; // x22
  unsigned int *v9; // x23
  unsigned int **v10; // x8
  unsigned int *v11; // x9
  __int64 v12; // x20
  int v19; // w8
  int v21; // w8

  v4 = kgsl_syncsource_get(*(_QWORD *)(a1 + 8), *(_DWORD *)a3);
  if ( !v4 )
    return -22;
  _X19 = v4;
  fence = sync_file_get_fence(*(unsigned int *)(a3 + 4));
  if ( fence )
  {
    v7 = fence;
    v8 = raw_spin_lock_irqsave(_X19 + 16);
    v9 = _X19 + 12;
    do
    {
      v9 = *(unsigned int **)v9;
      if ( v9 == _X19 + 12 )
      {
        v12 = -22;
        goto LABEL_13;
      }
    }
    while ( v9 - 18 != (unsigned int *)v7 );
    dma_fence_signal_locked(v7);
    v10 = *((unsigned int ***)v9 + 1);
    if ( *v10 == v9 && (v11 = *(unsigned int **)v9, *(unsigned int **)(*(_QWORD *)v9 + 8LL) == v9) )
    {
      *((_QWORD *)v11 + 1) = v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v9);
    }
    v12 = 0;
    *(_QWORD *)v9 = v9;
    *((_QWORD *)v9 + 1) = v9;
LABEL_13:
    raw_spin_unlock_irqrestore(_X19 + 16, v8);
    _X0 = (unsigned int *)(v7 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v19 = __ldxr(_X0);
    while ( __stlxr(v19 - 1, _X0) );
    if ( v19 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else if ( v19 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  else
  {
    v12 = -9;
  }
  __asm { PRFM            #0x11, [X19] }
  do
    v21 = __ldxr(_X19);
  while ( __stlxr(v21 - 1, _X19) );
  if ( v21 == 1 )
  {
    __dmb(9u);
    kgsl_process_private_put(*((unsigned int **)_X19 + 5));
    kfree(_X19);
  }
  else if ( v21 <= 0 )
  {
    refcount_warn_saturate(_X19, 3);
  }
  return v12;
}
