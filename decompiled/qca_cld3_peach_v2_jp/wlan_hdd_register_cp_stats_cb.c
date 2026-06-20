__int64 __fastcall wlan_hdd_register_cp_stats_cb(_QWORD *a1)
{
  return ucfg_mc_cp_stats_register_lost_link_info_cb(*a1, hdd_lost_link_cp_stats_info_cb);
}
