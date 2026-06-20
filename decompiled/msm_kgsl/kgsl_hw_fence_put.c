unsigned int *__fastcall kgsl_hw_fence_put(unsigned int *result)
{
  unsigned int *v1; // x19
  unsigned int *v2; // x20
  unsigned int **v3; // x8
  __int64 v4; // x9
  int v11; // w8
  unsigned __int64 v14; // x10
  int v16; // w8

  if ( result )
  {
    v1 = result;
    result += 32;
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(result);
    while ( __stlxr(v11 - 1, result) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      raw_spin_lock(&hw_fence_list_lock);
      v2 = v1 + 28;
      if ( *((unsigned int **)v1 + 14) != v1 + 28 )
      {
        synx_release(kgsl_synx, v1[26]);
        _X8 = (unsigned __int64 *)(v1 + 12);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 & 0xFFFFFFFF7FFFFFFFLL, _X8) );
        v3 = *((unsigned int ***)v1 + 15);
        if ( *v3 == v2 && (v4 = *(_QWORD *)v2, *(unsigned int **)(*(_QWORD *)v2 + 8LL) == v2) )
        {
          *(_QWORD *)(v4 + 8) = v3;
          *v3 = (unsigned int *)v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v1 + 28);
        }
        _X0 = v1 + 14;
        *((_QWORD *)v1 + 14) = v1 + 28;
        *((_QWORD *)v1 + 15) = v2;
        __asm { PRFM            #0x11, [X0] }
        do
          v16 = __ldxr(_X0);
        while ( __stlxr(v16 - 1, _X0) );
        if ( v16 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v16 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      return (unsigned int *)raw_spin_unlock(&hw_fence_list_lock);
    }
    else if ( v11 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
