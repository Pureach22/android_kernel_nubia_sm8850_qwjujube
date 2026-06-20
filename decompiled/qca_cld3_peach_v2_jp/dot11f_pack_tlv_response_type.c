__int64 __fastcall dot11f_pack_tlv_response_type(__int64 a1, _BYTE *a2, __int64 a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w9

  if ( a4 < 5 )
    return 268435461;
  if ( !*a2 )
    return 0;
  v6 = *a5;
  *(_WORD *)a3 = 15120;
  result = 0;
  *a5 += 4;
  *(_BYTE *)(a3 + 4) = a2[1];
  v7 = *a5 + 1;
  *a5 = v7;
  if ( a3 != -2 )
    *(_WORD *)(a3 + 2) = bswap32(v7 - v6 - 4) >> 16;
  return result;
}
