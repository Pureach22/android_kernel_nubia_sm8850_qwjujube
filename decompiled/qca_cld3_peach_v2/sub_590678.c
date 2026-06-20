__int64 __fastcall sub_590678(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return wlan_cp_stats_vdev_obj_destroy_handler(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           *(int *)wlan_cfg80211_mc_cp_stats_get_station_stats);
}
