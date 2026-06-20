unsigned int *__fastcall dma_fence_put(unsigned int *result)
{
  int v6; // w8

  if ( result )
  {
    result += 14;
    __asm { PRFM            #0x11, [X0] }
    do
      v6 = __ldxr(result);
    while ( __stlxr(v6 - 1, result) );
    if ( v6 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)dma_fence_release();
    }
    else if ( v6 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate();
    }
  }
  return result;
}
