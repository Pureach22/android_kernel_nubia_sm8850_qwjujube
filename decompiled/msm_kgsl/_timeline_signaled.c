unsigned int *__fastcall timeline_signaled(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int *result; // x0
  int v10; // w8
  int v13; // w8
  int v15; // w8
  __int64 (__fastcall *v16)(_QWORD); // x8

  result = (unsigned int *)(a3 + 56);
  __asm { PRFM            #0x11, [X0] }
  do
    v10 = __ldxr(result);
  while ( __stlxr(v10 - 1, result) );
  if ( v10 == 1 )
  {
    __dmb(9u);
    result = (unsigned int *)drawobj_timelineobj_retire();
    if ( !a3 )
      return result;
  }
  else if ( v10 <= 0 )
  {
    result = (unsigned int *)refcount_warn_saturate(result, 3);
    if ( !a3 )
      return result;
  }
  else if ( !a3 )
  {
    return result;
  }
  result = (unsigned int *)(a3 + 32);
  __asm { PRFM            #0x11, [X0] }
  do
    v13 = __ldxr(result);
  while ( __stlxr(v13 - 1, result) );
  if ( v13 == 1 )
  {
    __dmb(9u);
    _X0 = *(unsigned int **)(a3 + 8);
    if ( _X0 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr(_X0);
      while ( __stlxr(v15 - 1, _X0) );
      if ( v15 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy((__int64)_X0);
      }
      else if ( v15 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    v16 = *(__int64 (__fastcall **)(_QWORD))(a3 + 48);
    if ( *((_DWORD *)v16 - 1) != 287870130 )
      __break(0x8228u);
    return (unsigned int *)v16(a3);
  }
  else if ( v13 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
