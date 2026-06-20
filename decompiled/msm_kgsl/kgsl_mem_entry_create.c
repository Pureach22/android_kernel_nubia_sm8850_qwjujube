unsigned int *kgsl_mem_entry_create()
{
  unsigned int *result; // x0
  __int64 v1; // x1
  unsigned int v7; // w8
  unsigned int *v8; // x19

  result = (unsigned int *)_kmalloc_cache_noprof(clk_set_rate, 3520, 376);
  if ( result )
  {
    *result = 1;
    __asm { PRFM            #0x11, [X0] }
    do
      v7 = __ldxr(result);
    while ( __stxr(v7 + 1, result) );
    if ( v7 )
    {
      if ( (((v7 + 1) | v7) & 0x80000000) == 0 )
      {
LABEL_4:
        result[92] = 0;
        result[93] = 0;
        return result;
      }
      v1 = 1;
    }
    else
    {
      v1 = 2;
    }
    v8 = result;
    refcount_warn_saturate(result, v1);
    result = v8;
    goto LABEL_4;
  }
  return result;
}
