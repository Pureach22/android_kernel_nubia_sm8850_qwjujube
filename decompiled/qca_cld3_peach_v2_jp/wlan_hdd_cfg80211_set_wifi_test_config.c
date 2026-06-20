__int64 __fastcall wlan_hdd_cfg80211_set_wifi_test_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  unsigned int v10; // w19
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v11[0] = 0;
  result = _osif_vdev_sync_op_start(v8, v11, "wlan_hdd_cfg80211_set_wifi_test_config");
  if ( !(_DWORD)result )
  {
    v10 = _wlan_hdd_cfg80211_set_wifi_test_config(a1, a2, a3, a4);
    _osif_vdev_sync_op_stop(v11[0], "wlan_hdd_cfg80211_set_wifi_test_config");
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
