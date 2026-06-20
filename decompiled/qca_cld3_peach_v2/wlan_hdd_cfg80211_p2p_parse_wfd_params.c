__int64 __fastcall wlan_hdd_cfg80211_p2p_parse_wfd_params(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  int v19; // w0
  unsigned int v20; // w19
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 32);
  v21[0] = 0;
  result = _osif_vdev_sync_op_start(v7, v21, "wlan_hdd_cfg80211_p2p_parse_wfd_params");
  if ( !(_DWORD)result )
  {
    v9 = *(_QWORD *)(a2 + 32);
    if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
    {
      v18 = jiffies;
      if ( _wlan_hdd_cfg80211_p2p_parse_wfd_params___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM/Monitor mode",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "__wlan_hdd_cfg80211_p2p_parse_wfd_params");
        _wlan_hdd_cfg80211_p2p_parse_wfd_params___last_ticks = v18;
      }
      v19 = -1;
    }
    else
    {
      v19 = _wlan_hdd_validate_context(
              *(_QWORD *)(v9 + 2712),
              (__int64)"__wlan_hdd_cfg80211_p2p_parse_wfd_params",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17);
      if ( !v19 )
        v19 = osif_p2p_parse_wfd_params(v9 + 2688, a3, a4);
    }
    v20 = v19;
    _osif_vdev_sync_op_stop(v21[0], "wlan_hdd_cfg80211_p2p_parse_wfd_params");
    result = v20;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
