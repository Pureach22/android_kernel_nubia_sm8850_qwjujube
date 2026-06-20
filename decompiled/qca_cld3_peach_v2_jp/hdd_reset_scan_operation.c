_DWORD *__fastcall hdd_reset_scan_operation(_DWORD *result)
{
  unsigned int v1; // w8
  _DWORD *v2; // x19
  _DWORD *v3; // x19

  v1 = *(_DWORD *)(*(_QWORD *)result + 40LL);
  if ( v1 <= 0xB )
  {
    v2 = result;
    if ( ((1 << v1) & 0x885) != 0 )
    {
      wlan_hdd_scan_abort(result);
      result = (_DWORD *)wlan_hdd_cleanup_remain_on_channel_ctx(v2);
      if ( !*(_DWORD *)(*(_QWORD *)v2 + 40LL) )
      {
        result = (_DWORD *)_hdd_objmgr_get_vdev_by_user(v2, 79, "hdd_reset_scan_operation");
        if ( result )
        {
          v3 = result;
          wlan_cfg80211_sched_scan_stop();
          return (_DWORD *)_hdd_objmgr_put_vdev_by_user(v3, 79, "hdd_reset_scan_operation");
        }
      }
    }
    else if ( v1 == 1 )
    {
      result[586] = 0;
    }
    else if ( v1 == 3 )
    {
      return (_DWORD *)wlan_hdd_cleanup_remain_on_channel_ctx(result);
    }
  }
  return result;
}
