__int64 __fastcall _wlan_hdd_cfg80211_sap_suspend_allowed(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  if ( (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 8) != 0 )
  {
    v20 = "%s: SSR is ongoing";
  }
  else if ( *(_DWORD *)(a1 + 80) == 1 )
  {
    if ( *(_DWORD *)(a1 + 2620) )
    {
      v20 = "%s: channel switch progress";
    }
    else
    {
      if ( (unsigned int)wlan_vdev_is_dfs_cac_wait(a2) )
        return 0;
      v20 = "%s: CAC in progress";
    }
  }
  else
  {
    v20 = "%s: SAP not active";
  }
  qdf_trace_msg(0x33u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "__wlan_hdd_cfg80211_sap_suspend_allowed");
  return 4294967285LL;
}
