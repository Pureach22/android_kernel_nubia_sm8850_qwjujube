__int64 __fastcall cfg80211_background_cac_abort(__int64 a1)
{
  if ( a1 )
    return queue_work_on(32, cfg80211_wq, a1 - 376);
  __break(0x800u);
  return cfg80211_start_background_radar_detection();
}
