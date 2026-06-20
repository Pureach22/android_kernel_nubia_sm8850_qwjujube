unsigned int *__fastcall adreno_hwsched_syncobj_kfence_put(unsigned int *result)
{
  unsigned int *v1; // x19
  signed int v2; // w22
  __int64 v3; // x9
  int v9; // w8

  if ( result[34] )
  {
    v1 = result;
    v2 = 0;
    do
    {
      result = *(unsigned int **)(*((_QWORD *)v1 + 18) + 16LL * v2 + 8);
      if ( result )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v9 = __ldxr(result);
        while ( __stlxr(v9 - 1, result) );
        if ( v9 == 1 )
        {
          __dmb(9u);
          result = (unsigned int *)kgsl_context_destroy(result);
        }
        else if ( v9 <= 0 )
        {
          result = (unsigned int *)refcount_warn_saturate(result, 3);
        }
      }
      v3 = *((_QWORD *)v1 + 18) + 16LL * v2++;
      *(_QWORD *)(v3 + 8) = 0;
    }
    while ( v2 < v1[34] );
  }
  return result;
}
