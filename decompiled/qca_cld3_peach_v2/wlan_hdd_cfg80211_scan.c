__int64 __fastcall wlan_hdd_cfg80211_scan(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 result; // x0
  unsigned int v6; // w19
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 64);
  v7[0] = 0;
  v4 = *(_QWORD *)(v3 + 32);
  result = _osif_vdev_sync_op_start(v4, v7, "wlan_hdd_cfg80211_scan");
  if ( !(_DWORD)result )
  {
    v6 = _wlan_hdd_cfg80211_scan(*(_QWORD *)(v4 + 55520), a2, 0);
    _osif_vdev_sync_op_stop(v7[0], "wlan_hdd_cfg80211_scan");
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
