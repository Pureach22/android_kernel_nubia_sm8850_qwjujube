__int64 __fastcall nl80211_stop_p2p_device(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 v4; // x0

  v3 = *(_QWORD *)(a2 + 56);
  if ( *(_DWORD *)(v3 + 8) != 10 )
    return 4294967201LL;
  v4 = *(_QWORD *)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v4 + 664LL) )
    return 4294967201LL;
  cfg80211_stop_p2p_device(v4, v3);
  return 0;
}
