unsigned int *__fastcall kgsl_sharedmem_bind_fence_callback(__int64 a1)
{
  __int64 v1; // x19
  unsigned int *result; // x0
  int v8; // w8

  v1 = *(_QWORD *)(a1 + 32);
  result = (unsigned int *)dma_fence_signal(v1);
  if ( v1 )
  {
    result = (unsigned int *)(v1 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v8 = __ldxr(result);
    while ( __stlxr(v8 - 1, result) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)dma_fence_release(result);
    }
    else if ( v8 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
