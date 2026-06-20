__int64 __fastcall dot11f_pack_ie_bcn_reporting_detail(__int64 a1, _BYTE *a2, _BYTE *a3, int a4, int *a5)
{
  int v5; // w8
  __int64 result; // x0
  int v7; // w10

  if ( !*a2 )
    return 0;
  if ( !a4 )
    return 268435461;
  v5 = *a5;
  result = 0;
  *a3 = 2;
  *a5 += 2;
  a3[2] = a2[1];
  v7 = *a5 + 1;
  *a5 = v7;
  if ( a3 != (_BYTE *)-1LL )
    a3[1] = v7 - v5 - 2;
  return result;
}
