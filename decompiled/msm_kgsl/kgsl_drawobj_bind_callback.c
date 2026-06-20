unsigned int *__fastcall kgsl_drawobj_bind_callback(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  void (*v3)(void); // x8
  unsigned int *result; // x0
  unsigned __int64 v11; // x9
  int v13; // w8
  int v16; // w8
  int v18; // w8
  __int64 (__fastcall *v19)(_QWORD); // x8

  v1 = *(_QWORD **)(a1 + 32);
  v2 = *v1;
  _X8 = v1 + 7;
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 2, _X8) );
  v3 = *(void (**)(void))(*(_QWORD *)(v2 + 8752) + 184LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 2043251089 )
      __break(0x8228u);
    v3();
  }
  result = (unsigned int *)v1[1];
  if ( result )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v13 = __ldxr(result);
    while ( __stlxr(v13 - 1, result) );
    if ( v13 == 1 )
    {
      __dmb(9u);
      result = (unsigned int *)kgsl_context_destroy((__int64)result);
      if ( !v1 )
        return result;
      goto LABEL_16;
    }
    if ( v13 <= 0 )
    {
      result = (unsigned int *)refcount_warn_saturate(result, 3);
      if ( !v1 )
        return result;
      goto LABEL_16;
    }
  }
  if ( !v1 )
    return result;
LABEL_16:
  result = (unsigned int *)(v1 + 4);
  __asm { PRFM            #0x11, [X0] }
  do
    v16 = __ldxr(result);
  while ( __stlxr(v16 - 1, result) );
  if ( v16 == 1 )
  {
    __dmb(9u);
    _X0 = (unsigned int *)v1[1];
    if ( _X0 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( __stlxr(v18 - 1, _X0) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy((__int64)_X0);
      }
      else if ( v18 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    v19 = (__int64 (__fastcall *)(_QWORD))v1[6];
    if ( *((_DWORD *)v19 - 1) != 287870130 )
      __break(0x8228u);
    return (unsigned int *)v19(v1);
  }
  else if ( v16 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
