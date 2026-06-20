__int64 __fastcall drawobj_sync_func(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned __int64 v4; // x10
  __int64 v5; // x8
  __int64 v6; // x9
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  __int64 result; // x0
  unsigned __int64 v18; // x10
  int v20; // w8
  __int64 v23; // x19
  int v25; // w9
  int v27; // w9
  __int64 (*v28)(void); // x8

  v4 = *a3;
  v5 = *((_QWORD *)a3 + 1);
  v6 = 1LL << v4;
  _X11 = (unsigned __int64 *)(v5 + 72 + 8 * (v4 >> 6));
  __asm { PRFM            #0x11, [X11] }
  do
    v18 = __ldxr(_X11);
  while ( __stlxr(v18 & ~v6, _X11) );
  __dmb(0xBu);
  if ( (v18 & v6) == 0 )
    goto LABEL_17;
  if ( !*(_DWORD *)(*((_QWORD *)a3 + 1) + 72LL) )
  {
    timer_delete((timer_t)(v5 + 80));
    v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 184LL);
    if ( v8 )
    {
      v9 = *(_QWORD *)(*((_QWORD *)a3 + 1) + 8LL);
      if ( *((_DWORD *)v8 - 1) != 2043251089 )
        __break(0x8228u);
      v8(a1, v9);
    }
  }
  _X0 = *((unsigned int **)a3 + 2);
  if ( !_X0 )
    goto LABEL_17;
  __asm { PRFM            #0x11, [X0] }
  do
    v20 = __ldxr(_X0);
  while ( __stlxr(v20 - 1, _X0) );
  if ( v20 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy((__int64)_X0);
    result = *((_QWORD *)a3 + 1);
    if ( !result )
      return result;
    goto LABEL_18;
  }
  if ( v20 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
    result = *((_QWORD *)a3 + 1);
    if ( !result )
      return result;
  }
  else
  {
LABEL_17:
    result = *((_QWORD *)a3 + 1);
    if ( !result )
      return result;
  }
LABEL_18:
  _X8 = (unsigned int *)(result + 32);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stlxr(v25 - 1, _X8) );
  if ( v25 != 1 )
  {
    if ( v25 <= 0 )
      return refcount_warn_saturate(result + 32, 3);
    return result;
  }
  __dmb(9u);
  _X8 = *(unsigned int **)(result + 8);
  if ( _X8 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stlxr(v27 - 1, _X8) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      v23 = result;
      kgsl_context_destroy((__int64)_X8);
    }
    else
    {
      if ( v27 > 0 )
        goto LABEL_32;
      v23 = result;
      refcount_warn_saturate(_X8, 3);
    }
    result = v23;
  }
LABEL_32:
  v28 = *(__int64 (**)(void))(result + 48);
  if ( *((_DWORD *)v28 - 1) != 287870130 )
    __break(0x8228u);
  return v28();
}
