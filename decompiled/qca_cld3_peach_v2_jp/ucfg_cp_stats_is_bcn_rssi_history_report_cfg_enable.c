__int64 __fastcall ucfg_cp_stats_is_bcn_rssi_history_report_cfg_enable(__int64 a1)
{
  return wlan_cp_stats_is_bcn_rssi_history_report_cfg_enable(a1) & 1;
}
