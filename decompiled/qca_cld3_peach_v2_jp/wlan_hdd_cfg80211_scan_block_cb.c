__int64 __fastcall wlan_hdd_cfg80211_scan_block_cb(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 41672);
  v4[0] = 0;
  result = _osif_vdev_sync_op_start(v2, v4, "wlan_hdd_cfg80211_scan_block_cb");
  if ( !(_DWORD)result )
  {
    wlan_hdd_cfg80211_scan_block(a1 - 41704);
    result = _osif_vdev_sync_op_stop(v4[0], "wlan_hdd_cfg80211_scan_block_cb");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
