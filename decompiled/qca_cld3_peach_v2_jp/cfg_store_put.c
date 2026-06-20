__int64 *__fastcall cfg_store_put(__int64 *result)
{
  unsigned int v7; // w8
  unsigned int v8; // w8

  _X9 = (unsigned int *)(result + 3);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v7 = __ldxr(_X9);
    v8 = v7 - 1;
  }
  while ( __stlxr(v8, _X9) );
  __dmb(0xBu);
  if ( !v8 )
    return (__int64 *)cfg_store_free(result);
  return result;
}
