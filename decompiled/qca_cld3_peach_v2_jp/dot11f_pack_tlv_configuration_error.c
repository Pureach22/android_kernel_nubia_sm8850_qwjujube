__int64 __fastcall dot11f_pack_tlv_configuration_error(__int64 a1, __int64 a2, _WORD *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w9

  if ( a4 < 6 )
    return 268435461;
  if ( !*(_BYTE *)a2 )
    return 0;
  v6 = *a5;
  *a3 = 2320;
  result = 0;
  *a5 += 4;
  a3[2] = bswap32(*(unsigned __int16 *)(a2 + 2)) >> 16;
  v7 = *a5 + 2;
  *a5 = v7;
  if ( a3 != (_WORD *)-2LL )
    a3[1] = bswap32(v7 - v6 - 4) >> 16;
  return result;
}
