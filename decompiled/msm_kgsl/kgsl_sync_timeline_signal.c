unsigned int *__fastcall kgsl_sync_timeline_signal(unsigned int *result, unsigned int a2)
{
  unsigned int v2; // w8
  unsigned int v5; // w20
  unsigned int v11; // w9
  __int64 v12; // x0
  unsigned int v13; // w8
  __int64 v14; // x20
  unsigned int v15; // w8
  unsigned int v16; // w8
  unsigned int *v17; // x21
  unsigned int *v18; // x26
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int **v20; // x8
  unsigned int *v21; // x9
  int v24; // w8
  int v26; // w8

  v2 = *result;
  _X19 = result;
  if ( *result )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v11 = __ldxr(result);
      while ( v11 == v2 && __stxr(v2 + 1, result) );
      v5 = v2;
      if ( v11 == v2 )
        break;
      v5 = 0;
      v2 = v11;
    }
    while ( v11 );
  }
  else
  {
    v5 = 0;
  }
  if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
  {
    result = (unsigned int *)refcount_warn_saturate(result, 0);
    if ( !v5 )
      return result;
  }
  else if ( !v5 )
  {
    return result;
  }
  v12 = raw_spin_lock_irqsave(_X19 + 16);
  v13 = _X19[17];
  v14 = v12;
  if ( a2 != v13 )
  {
    if ( a2 > v13 && ((a2 - v13) & 0x80000000) == 0
      || (v15 = v13 ^ 0x80000000, _CF = (a2 ^ 0x80000000) >= v15, v16 = (a2 ^ 0x80000000) - v15, v16 != 0 && _CF)
      && v16 <= 0x80000000 )
    {
      _X19[17] = a2;
    }
  }
  v17 = *((unsigned int **)_X19 + 6);
  if ( v17 != _X19 + 12 )
  {
    do
    {
      v18 = *(unsigned int **)v17;
      if ( (*((_QWORD *)v17 - 4) & 1) == 0 )
      {
        v19 = *(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)v17 - 9) + 32LL);
        if ( !v19 )
          goto LABEL_22;
        if ( *((_DWORD *)v19 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v19(v17 - 20) & 1) == 0 )
          goto LABEL_22;
        dma_fence_signal_locked(v17 - 20);
      }
      kgsl_hw_fence_put(v17 - 20);
      v20 = *((unsigned int ***)v17 + 1);
      if ( *v20 == v17 && (v21 = *(unsigned int **)v17, *(unsigned int **)(*(_QWORD *)v17 + 8LL) == v17) )
      {
        *((_QWORD *)v21 + 1) = v20;
        *v20 = v21;
      }
      else
      {
        _list_del_entry_valid_or_report(v17);
      }
      *(_QWORD *)v17 = v17;
      *((_QWORD *)v17 + 1) = v17;
      if ( v17 != (unsigned int *)&unk_50 )
      {
        _X0 = v17 - 6;
        __asm { PRFM            #0x11, [X0] }
        do
          v24 = __ldxr(_X0);
        while ( __stlxr(v24 - 1, _X0) );
        if ( v24 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v24 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
LABEL_22:
      v17 = v18;
    }
    while ( v18 != _X19 + 12 );
  }
  result = (unsigned int *)raw_spin_unlock_irqrestore(_X19 + 16, v14);
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v26 = __ldxr(_X19);
    while ( __stlxr(v26 - 1, _X19) );
    if ( v26 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)kfree(_X19);
    }
    else if ( v26 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(_X19, 3);
    }
  }
  return result;
}
