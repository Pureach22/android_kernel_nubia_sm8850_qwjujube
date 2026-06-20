unsigned int *__fastcall kref_get(unsigned int *result)
{
  __int64 v1; // x1
  unsigned int v7; // w8

  __asm { PRFM            #0x11, [X0] }
  do
    v7 = __ldxr(result);
  while ( __stxr(v7 + 1, result) );
  if ( v7 )
  {
    if ( (((v7 + 1) | v7) & 0x80000000) == 0 )
      return result;
    v1 = 1;
  }
  else
  {
    v1 = 2;
  }
  return (unsigned int *)refcount_warn_saturate(result, v1);
}
