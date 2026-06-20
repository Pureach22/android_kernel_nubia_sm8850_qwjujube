unsigned int *__fastcall drm_atomic_state_put(unsigned int *result)
{
  int v6; // w8

  __asm { PRFM            #0x11, [X0] }
  do
    v6 = __ldxr(result);
  while ( __stlxr(v6 - 1, result) );
  if ( v6 == 1 )
  {
    __dmb(9u);
    return (unsigned int *)_drm_atomic_state_free(result);
  }
  else if ( v6 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
