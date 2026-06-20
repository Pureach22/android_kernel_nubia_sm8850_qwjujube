__int64 __fastcall synx_util_get_free_handle(__int64 a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x8
  unsigned __int64 v12; // x9

  v3 = a2;
  do
  {
    result = find_first_zero_bit(a1, v3);
    if ( result >= v3 )
      break;
    v5 = 1LL << result;
    _X10 = (unsigned __int64 *)(a1 + 8LL * ((unsigned int)result >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v12 = __ldxr(_X10);
    while ( __stlxr(v12 | v5, _X10) );
    __dmb(0xBu);
  }
  while ( (v12 & v5) != 0 );
  return result;
}
