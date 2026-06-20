__int64 __fastcall kgsl_syncsource_put(__int64 result)
{
  __int64 v1; // x19
  int v7; // w8

  if ( result )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v7 = __ldxr((unsigned int *)result);
    while ( __stlxr(v7 - 1, (unsigned int *)result) );
    if ( v7 == 1 )
    {
      __dmb(9u);
      v1 = result;
      kgsl_process_private_put(*(unsigned int **)(result + 40));
      return kfree(v1);
    }
    else if ( v7 <= 0 )
    {
      return refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
