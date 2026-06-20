__int64 __fastcall wlan_hdd_cfg80211_set_aggressive_roaming(__int64 a1, __int64 a2, int a3)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19

  v6 = sme_set_aggressive_roaming(*(_QWORD *)(a1 + 16), *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL), 1);
  if ( !v6 )
  {
    v6 = ucfg_user_space_enable_disable_rso(
           *(_QWORD *)(a1 + 8),
           *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL),
           a3 != 0);
    if ( v6 )
    {
      v15 = v6;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: ROAM_CONFIG: sme_config_fast_roaming failed with status=%d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "wlan_hdd_cfg80211_set_aggressive_roaming",
        v6);
      v6 = v15;
    }
  }
  return qdf_status_to_os_return(v6);
}
