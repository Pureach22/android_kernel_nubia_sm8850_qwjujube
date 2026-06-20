void __fastcall ieee80211_radar_mark_chan_ctx_iterator(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_DWORD *)(a2 - 88) != 2 && (!a3 || a3 == a2) )
    *(_BYTE *)(a2 + 104) = 1;
}
