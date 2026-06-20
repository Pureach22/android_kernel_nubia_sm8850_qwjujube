unsigned int *__fastcall sock_put(__int64 a1)
{
  unsigned int *result; // x0
  int v8; // w9

  result = (unsigned int *)(a1 + 128);
  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(result);
  while ( __stlxr(v8 - 1, result) );
  if ( v8 == 1 )
  {
    __dmb(9u);
    return (unsigned int *)sk_free(a1);
  }
  else if ( v8 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
