__int64 __fastcall ieee80211_sta_cap_chan_bw(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w8
  unsigned int v3; // w9

  v1 = *(_QWORD *)(a1 + 920);
  if ( (*(_BYTE *)(v1 + 68) & 1) != 0 )
  {
    v2 = *(_DWORD *)(v1 + 72) & 0xC;
    if ( v2 == 8 )
      v3 = 4;
    else
      v3 = 3;
    if ( v2 == 4 )
      return 5;
    else
      return v3;
  }
  else if ( *(_BYTE *)(v1 + 46) == 1 )
  {
    if ( (*(_WORD *)(v1 + 44) & 2) != 0 )
      return 2;
    else
      return 1;
  }
  else
  {
    return 0;
  }
}
