unsigned int *__fastcall kgsl_gpumem_vm_close(__int64 a1)
{
  unsigned int *result; // x0
  __int64 v2; // x8
  unsigned int v9; // w8
  unsigned int v10; // w8
  int v12; // w8
  unsigned __int64 v15; // x10

  result = *(unsigned int **)(a1 + 96);
  if ( result )
  {
    _X9 = result + 92;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v9 = __ldxr(_X9);
      v10 = v9 - 1;
    }
    while ( __stlxr(v10, _X9) );
    __dmb(0xBu);
    if ( !v10 )
    {
      v2 = *((_QWORD *)result + 6);
      _X9 = (unsigned __int64 *)(*((_QWORD *)result + 32) + 336LL);
      __asm { PRFM            #0x11, [X9] }
      do
        v15 = __ldxr(_X9);
      while ( __stxr(v15 - v2, _X9) );
    }
    if ( (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v12 = __ldxr(result);
      while ( __stlxr(v12 - 1, result) );
      if ( v12 == 1 )
      {
        __dmb(9u);
        return (unsigned int *)kgsl_mem_entry_destroy(result);
      }
      else if ( v12 <= 0 )
      {
        return (unsigned int *)refcount_warn_saturate(result, 3);
      }
    }
  }
  return result;
}
