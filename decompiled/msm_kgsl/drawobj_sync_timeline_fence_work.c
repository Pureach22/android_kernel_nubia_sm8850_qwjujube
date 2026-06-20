__int64 __fastcall drawobj_sync_timeline_fence_work(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  int v10; // w9
  __int64 v13; // x19
  int v15; // w9
  int v17; // w9
  __int64 (*v18)(void); // x8
  __int64 v20; // [xsp+18h] [xbp+18h]

  v1 = *(_QWORD *)(a1 - 32);
  if ( v1 )
  {
    _X8 = (unsigned int *)(v1 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stlxr(v10 - 1, _X8) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X8);
      result = *(_QWORD *)(a1 - 80);
      if ( !result )
        return result;
      goto LABEL_9;
    }
    if ( v10 <= 0 )
    {
      refcount_warn_saturate(_X8, 3);
      result = *(_QWORD *)(a1 - 80);
      if ( !result )
        return result;
      goto LABEL_9;
    }
  }
  result = *(_QWORD *)(a1 - 80);
  if ( !result )
    return result;
LABEL_9:
  _X8 = (unsigned int *)(result + 32);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stlxr(v15 - 1, _X8) );
  if ( v15 == 1 )
  {
    __dmb(9u);
    _X8 = *(unsigned int **)(result + 8);
    if ( _X8 )
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stlxr(v17 - 1, _X8) );
      if ( v17 == 1 )
      {
        __dmb(9u);
        v13 = result;
        kgsl_context_destroy((__int64)_X8);
        result = v13;
      }
      else if ( v17 <= 0 )
      {
        v20 = result;
        refcount_warn_saturate(_X8, 3);
        result = v20;
      }
    }
    v18 = *(__int64 (**)(void))(result + 48);
    if ( *((_DWORD *)v18 - 1) != 287870130 )
      __break(0x8228u);
    return v18();
  }
  else if ( v15 <= 0 )
  {
    return refcount_warn_saturate(result + 32, 3);
  }
  return result;
}
