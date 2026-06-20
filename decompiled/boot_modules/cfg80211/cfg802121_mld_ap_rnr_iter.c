__int64 __fastcall cfg802121_mld_ap_rnr_iter(__int64 a1, char a2, __int64 a3, unsigned __int8 *a4, unsigned __int8 a5)
{
  unsigned __int8 v5; // w8
  bool v6; // w9
  unsigned int v7; // w8
  int v8; // w9

  if ( a2 || a5 < 0x10u )
  {
    if ( a2 != 1 )
      return 0;
    v6 = 0;
    if ( a5 < 3u )
      return 0;
  }
  else
  {
    v5 = a4[11];
    a4 += 13;
    v6 = (v5 & 0xC) == 4;
  }
  if ( *(unsigned __int8 *)(a1 + 16) != *a4 || *(_BYTE *)(a1 + 17) != (a4[1] & 0xF) )
    return 0;
  *(_QWORD *)a1 = a3;
  v7 = *(unsigned __int16 *)(a4 + 1);
  *(_BYTE *)(a1 + 18) = v6;
  if ( a2 )
    v8 = 2;
  else
    v8 = 3;
  *(_DWORD *)(a1 + 12) = v8;
  *(_BYTE *)(a1 + 8) = v7 >> 4;
  return 1;
}
