__int64 __fastcall wlan_hdd_cfg80211_set_default_beacon_key(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v11, "wlan_hdd_cfg80211_set_default_beacon_key");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v3, v4, v5, v6, v7, v8, v9, v10, "_wlan_hdd_cfg80211_set_default_beacon_key");
    _osif_vdev_sync_op_stop(v11[0], "wlan_hdd_cfg80211_set_default_beacon_key");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
