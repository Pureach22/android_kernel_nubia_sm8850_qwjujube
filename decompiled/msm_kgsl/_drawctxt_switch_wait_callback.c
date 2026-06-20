__int64 __fastcall drawctxt_switch_wait_callback(__int64 a1, __int64 a2, unsigned int *_X2)
{
  __int64 result; // x0
  int v9; // w8

  if ( _X2 )
  {
    __asm { PRFM            #0x11, [X2] }
    do
      v9 = __ldxr(_X2);
    while ( __stlxr(v9 - 1, _X2) );
    if ( v9 == 1 )
    {
      __dmb(9u);
      return kgsl_context_destroy(_X2);
    }
    else if ( v9 <= 0 )
    {
      return refcount_warn_saturate(_X2, 3);
    }
  }
  return result;
}
