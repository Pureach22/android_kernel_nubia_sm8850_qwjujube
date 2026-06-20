__int64 __fastcall ucfg_cp_stats_get_chipset_stats_enable(__int64 a1)
{
  return wlan_cp_stats_get_chipset_stats_enable(a1) & 1;
}
