__int64 __fastcall wlan_pdev_chan_change_pending_vdevs(__int64 a1, __int64 a2, unsigned int a3)
{
  if ( !a1 )
    return 4;
  wlan_objmgr_pdev_iterate_obj_list(
    a1,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))wlan_vdev_chan_change_pending,
    a2,
    0,
    a3);
  return 0;
}
