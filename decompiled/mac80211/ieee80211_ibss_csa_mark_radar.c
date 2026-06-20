__int64 __fastcall ieee80211_ibss_csa_mark_radar(__int64 a1)
{
  __int64 result; // x0

  result = cfg80211_chandef_dfs_required(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2400, 1);
  if ( (int)result >= 1 )
    return _cfg80211_radar_event(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2400, 0, 2080);
  return result;
}
