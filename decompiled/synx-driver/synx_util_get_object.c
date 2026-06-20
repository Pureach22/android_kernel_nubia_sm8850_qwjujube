unsigned int *__fastcall synx_util_get_object(__int64 a1)
{
  unsigned int *result; // x0
  __int64 v2; // x1
  unsigned int v8; // w8

  result = (unsigned int *)(a1 + 120);
  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(result);
  while ( __stxr(v8 + 1, result) );
  if ( v8 )
  {
    if ( (((v8 + 1) | v8) & 0x80000000) == 0 )
      return result;
    v2 = 1;
  }
  else
  {
    v2 = 2;
  }
  return (unsigned int *)refcount_warn_saturate(result, v2);
}
