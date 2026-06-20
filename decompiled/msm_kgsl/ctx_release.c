__int64 __fastcall ctx_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x20
  int v10; // w9
  __int64 v12; // [xsp+0h] [xbp-10h]
  __int64 v13; // [xsp+8h] [xbp-8h]

  _X8 = *(unsigned int **)(*(_QWORD *)(a2 + 32) + 128LL);
  if ( _X8 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stlxr(v10 - 1, _X8) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      v3 = a1;
      v4 = a2;
      kgsl_context_destroy((__int64)_X8);
      a1 = v3;
      a2 = v4;
    }
    else if ( v10 <= 0 )
    {
      v12 = a2;
      v13 = a1;
      refcount_warn_saturate(_X8, 3);
      a2 = v12;
      a1 = v13;
    }
  }
  return single_release(a1, a2);
}
