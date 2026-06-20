__int64 __fastcall nl80211_check_scan_flags(_BYTE *a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  __int64 v5; // x11
  unsigned int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x12
  int v10; // w11
  __int64 result; // x0

  v5 = *(_QWORD *)(a4 + 1264);
  if ( !v5 )
    return 0;
  if ( (a5 & 1) != 0 )
  {
    if ( a2 )
      v6 = 0x40000000;
    else
      v6 = 0x80000000;
    v7 = 90;
    v8 = 84;
    v9 = 40;
  }
  else
  {
    v6 = 0x20000000;
    v7 = 78;
    v8 = 72;
    v9 = 36;
  }
  v10 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(a3 + v9) = v10;
  if ( (v10 & 1) != 0 && (a1[108] & 0x40) == 0
    || (v10 & 0x100) != 0 && (a1[114] & 0x40) == 0
    || (v10 & 0x200) != 0 && ((char)a1[114] & 0x80000000) == 0
    || (v10 & 0x400) != 0 && (a1[115] & 1) == 0
    || (v10 & 0x10) != 0 && (a1[114] & 2) == 0
    || (v10 & 0x20) != 0 && (a1[114] & 4) == 0
    || (v10 & 0x80) != 0 && (a1[114] & 0x10) == 0
    || (v10 & 0x40) != 0 && (a1[114] & 8) == 0
    || (v10 & 0x800) != 0 && (a1[115] & 0x20) == 0
    || (v10 & 0x1000) != 0 && (a1[115] & 0x40) == 0 )
  {
    return 4294967201LL;
  }
  if ( (v10 & 8) == 0 )
    return 0;
  if ( (*((_DWORD *)a1 + 27) & v6) == 0 || a2 && (*(_BYTE *)(a2 + 164) & 1) != 0 )
    return 4294967201LL;
  result = nl80211_parse_random_mac(a4, (int *)(a3 + v8), a3 + v7);
  if ( !(_DWORD)result )
    return 0;
  return result;
}
