__int64 __fastcall dot11f_pack_ie_wmmtclasproc(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w10

  if ( !*a2 )
    return 0;
  if ( a4 < 2 )
    return 268435461;
  v6 = *a5;
  *a3 = -35;
  result = 0;
  *a5 += 2;
  a3[2] = 0;
  ++*a5;
  a3[3] = 80;
  ++*a5;
  a3[4] = -14;
  ++*a5;
  a3[5] = 2;
  ++*a5;
  a3[6] = 7;
  ++*a5;
  a3[7] = a2[1];
  ++*a5;
  a3[8] = a2[2];
  v7 = *a5 + 1;
  *a5 = v7;
  if ( a3 != (_BYTE *)-1LL )
    a3[1] = v7 - v6 - 2;
  return result;
}
