bool __fastcall ieee80211_scan_accept_presp(__int64 a1, _DWORD *a2, char a3, _WORD *a4)
{
  int v4; // w9

  if ( !a1 )
    return 0;
  v4 = (unsigned __int16)a4[2];
  if ( (unsigned __int16)(a4[1] & *a4 & v4) == 0xFFFF )
  {
    if ( (a3 & 0x28) != 0 || *a2 == 3 )
      return 1;
  }
  else if ( (a3 & 8) != 0 )
  {
    return 1;
  }
  return *(_DWORD *)(a1 + 5842) == *(_DWORD *)a4 && *(unsigned __int16 *)(a1 + 5846) == v4;
}
