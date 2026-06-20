unsigned int *__fastcall fastrpc_channel_ctx_get(__int64 a1)
{
  unsigned int *result; // x0
  unsigned int v7; // w8

  result = (unsigned int *)(a1 + 51664);
  __asm { PRFM            #0x11, [X0] }
  do
    v7 = __ldxr(result);
  while ( __stxr(v7 + 1, result) );
  if ( !v7 || (((v7 + 1) | v7) & 0x80000000) != 0 )
    return (unsigned int *)refcount_warn_saturate();
  return result;
}
