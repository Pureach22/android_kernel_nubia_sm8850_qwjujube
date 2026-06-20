__int64 __fastcall dot11f_pack_ie_rrm_enabled_cap(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w10

  if ( !*(_BYTE *)a2 )
    return 0;
  if ( a4 < 5 )
    return 268435461;
  v6 = *a5;
  result = 0;
  *a3 = 70;
  *a5 += 2;
  a3[2] = *(_DWORD *)(a2 + 1);
  ++*a5;
  a3[3] = BYTE1(*(_DWORD *)(a2 + 1));
  ++*a5;
  a3[4] = *(_WORD *)(a2 + 3);
  ++*a5;
  a3[5] = *(_BYTE *)(a2 + 4);
  ++*a5;
  a3[6] = *(_BYTE *)(a2 + 5);
  v7 = *a5 + 1;
  *a5 = v7;
  if ( a3 != (_BYTE *)-1LL )
    a3[1] = v7 - v6 - 2;
  return result;
}
