__int64 __fastcall wlan_hdd_cfg80211_connect(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w19
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v8, "wlan_hdd_cfg80211_connect");
  if ( !(_DWORD)result )
  {
    v7 = wlan_hdd_cm_connect(a1, a2, a3);
    _osif_vdev_sync_op_stop(v8[0], "wlan_hdd_cfg80211_connect");
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
