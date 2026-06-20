__int64 __fastcall wlan_objmgr_psoc_check_for_leaks(__int64 a1)
{
  wlan_objmgr_psoc_check_for_peer_leaks(a1);
  wlan_objmgr_psoc_check_for_vdev_leaks(a1);
  return wlan_objmgr_psoc_check_for_pdev_leaks(a1);
}
