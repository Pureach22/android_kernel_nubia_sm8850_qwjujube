unsigned int *__fastcall kgsl_mem_entry_put(unsigned int *result)
{
  int v6; // w8

  if ( result && (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v6 = __ldxr(result);
    while ( __stlxr(v6 - 1, result) );
    if ( v6 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)kgsl_mem_entry_destroy();
    }
    else if ( v6 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
