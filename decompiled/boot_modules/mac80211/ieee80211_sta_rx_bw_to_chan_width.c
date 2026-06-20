__int64 __fastcall ieee80211_sta_rx_bw_to_chan_width(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9

  v1 = *(_QWORD *)(a1 + 920);
  v2 = *(_DWORD *)(v1 + 232);
  if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      return 3;
    }
    else
    {
      if ( v2 != 3 )
        return 1;
      if ( (*(_DWORD *)(v1 + 72) & 0xC) == 4 )
        return 5;
      else
        return 4;
    }
  }
  else
  {
    if ( v2 )
    {
      if ( v2 == 1 )
        return 2;
      return 1;
    }
    return *(unsigned __int8 *)(v1 + 46);
  }
}
