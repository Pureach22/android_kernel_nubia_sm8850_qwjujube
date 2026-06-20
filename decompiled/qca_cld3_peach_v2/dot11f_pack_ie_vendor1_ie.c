__int64 __fastcall dot11f_pack_ie_vendor1_ie(__int64 a1, _BYTE *a2, _BYTE *a3, __int64 a4, int *a5)
{
  int v5; // w8
  int v6; // w10

  if ( *a2 )
  {
    v5 = *a5;
    *a3 = -35;
    *a5 += 2;
    a3[2] = 0;
    ++*a5;
    a3[3] = 16;
    ++*a5;
    a3[4] = 24;
    v6 = *a5 + 1;
    *a5 = v6;
    if ( a3 != (_BYTE *)-1LL )
      a3[1] = v6 - v5 - 2;
  }
  return 0;
}
