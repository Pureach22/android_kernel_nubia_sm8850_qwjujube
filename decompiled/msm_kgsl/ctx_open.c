__int64 __fastcall ctx_open(__int64 a1, __int64 a2)
{
  unsigned int v3; // w8
  unsigned int v4; // w20
  unsigned int v10; // w9
  __int64 result; // x0
  unsigned int v12; // w20
  __int64 v13; // x21
  int v15; // w8

  _X19 = *(unsigned int **)(a1 + 696);
  if ( !_X19 )
    return 4294967277LL;
  v3 = *_X19;
  if ( *_X19 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v10 = __ldxr(_X19);
      while ( v10 == v3 && __stxr(v3 + 1, _X19) );
      v4 = v3;
      if ( v10 == v3 )
        break;
      v4 = 0;
      v3 = v10;
    }
    while ( v10 );
  }
  else
  {
    v4 = 0;
  }
  if ( (((v4 + 1) | v4) & 0x80000000) == 0 )
  {
    if ( v4 )
      goto LABEL_13;
    return 4294967277LL;
  }
  v13 = a2;
  refcount_warn_saturate(_X19, 0);
  a2 = v13;
  if ( !v4 )
    return 4294967277LL;
LABEL_13:
  result = single_open(a2, ctx_print, _X19);
  if ( (_DWORD)result )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v15 = __ldxr(_X19);
    while ( __stlxr(v15 - 1, _X19) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      v12 = result;
      kgsl_context_destroy((__int64)_X19);
      return v12;
    }
    if ( v15 <= 0 )
    {
      v12 = result;
      refcount_warn_saturate(_X19, 3);
      return v12;
    }
  }
  return result;
}
