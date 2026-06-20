__int64 __fastcall dot11f_pack_tlv_transition_reason(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w10

  if ( a4 < 3 )
    return 268435461;
  if ( !*a2 )
    return 0;
  v6 = *a5;
  result = 0;
  *a3 = 6;
  *a5 += 2;
  a3[2] = a2[1];
  v7 = *a5 + 1;
  *a5 = v7;
  if ( a3 != (_BYTE *)-1LL )
    a3[1] = v7 - v6 - 2;
  return result;
}
