__int64 __fastcall kgsl_drawobj_destroy_object(__int64 a1)
{
  __int64 v2; // x19
  int v8; // w9
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  __int64 v12; // [xsp+18h] [xbp+18h]

  _X8 = *(unsigned int **)(a1 - 24);
  if ( _X8 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stlxr(v8 - 1, _X8) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      v2 = a1;
      kgsl_context_destroy((__int64)_X8);
      a1 = v2;
    }
    else if ( v8 <= 0 )
    {
      v12 = a1;
      refcount_warn_saturate(_X8, 3);
      a1 = v12;
    }
  }
  v9 = *(__int64 (__fastcall **)(_QWORD))(a1 + 16);
  v10 = a1 - 32;
  if ( *((_DWORD *)v9 - 1) != 287870130 )
    __break(0x8228u);
  return v9(v10);
}
