__int64 __fastcall wlan_hdd_cfg80211_set_fast_roaming(__int64 *a1, __int64 a2, int a3)
{
  __int64 v3; // x24
  unsigned int v6; // w0
  __int64 result; // x0
  bool is_rso_enabled; // w21
  unsigned int v9; // w22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w0
  unsigned int v19; // w23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v3 = a2 + 49152;
  v6 = sme_set_aggressive_roaming(a1[2], *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL), 0);
  if ( v6 )
    return qdf_status_to_os_return(v6);
  is_rso_enabled = ucfg_is_rso_enabled(a1[1], *(unsigned __int8 *)(*(_QWORD *)(v3 + 3672) + 8LL));
  v9 = ucfg_user_space_enable_disable_rso(a1[1], *(unsigned __int8 *)(*(_QWORD *)(v3 + 3672) + 8LL), a3 != 0);
  if ( v9
    && (qdf_trace_msg(
          0x33u,
          2u,
          "%s: ROAM_CONFIG: sme_config_fast_roaming failed with status=%d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "wlan_hdd_cfg80211_set_fast_roaming",
          v9),
        v9 == 6) )
  {
    v18 = 0;
  }
  else
  {
    v18 = v9;
  }
  v19 = qdf_status_to_os_return(v18);
  if ( (hdd_cm_is_vdev_associated(*(_QWORD *)(v3 + 3672)) & 1) == 0
    || (ucfg_mlme_is_roaming_offload_enabled(*a1) & 1) == 0 )
  {
    return v19;
  }
  result = v19;
  if ( !a3 && is_rso_enabled && v9 == 0 )
  {
    *(_DWORD *)(v3 + 2912) = 0;
    if ( wait_for_completion_timeout(v3 + 2912, 500) )
    {
      result = v19;
      if ( !*(_DWORD *)(v3 + 2904) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Roam disable attempt in FW fails",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_hdd_cfg80211_set_fast_roaming");
        return 4294967280LL;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Timed out waiting for RSO CMD status",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_hdd_cfg80211_set_fast_roaming");
      return 4294967186LL;
    }
  }
  return result;
}
