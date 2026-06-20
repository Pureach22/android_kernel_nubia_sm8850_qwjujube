__int64 __fastcall kgsl_sync_fence_release(__int64 a1)
{
  __int64 v2; // x19
  int v8; // w9
  __int64 v10; // [xsp+18h] [xbp+18h]

  _X8 = *(unsigned int **)(a1 + 72);
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
      kfree(_X8);
      a1 = v2;
    }
    else if ( v8 <= 0 )
    {
      v10 = a1;
      refcount_warn_saturate(_X8, 3);
      a1 = v10;
    }
  }
  return kfree(a1);
}
