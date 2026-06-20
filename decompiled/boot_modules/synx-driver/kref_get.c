unsigned int *__fastcall kref_get(unsigned int *result)
{
  unsigned int v6; // w8

  __asm { PRFM            #0x11, [X0] }
  do
    v6 = __ldxr(result);
  while ( __stxr(v6 + 1, result) );
  if ( !v6 || (((v6 + 1) | v6) & 0x80000000) != 0 )
    return (unsigned int *)refcount_warn_saturate();
  return result;
}
