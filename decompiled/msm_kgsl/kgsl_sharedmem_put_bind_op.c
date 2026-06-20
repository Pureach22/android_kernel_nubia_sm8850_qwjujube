unsigned __int64 __fastcall kgsl_sharedmem_put_bind_op(unsigned __int64 result)
{
  int v7; // w9

  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    _X8 = (unsigned int *)(result + 104);
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr(_X8);
    while ( __stlxr(v7 - 1, _X8) );
    if ( v7 == 1 )
    {
      __dmb(9u);
      return kgsl_sharedmem_free_bind_op(result);
    }
    else if ( v7 <= 0 )
    {
      return refcount_warn_saturate(result + 104, 3);
    }
  }
  return result;
}
