__int64 __fastcall wlan_vdev_mlme_notify_set_mac_addr_response(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 + 64);
  if ( (v1 & 0x2000000) != 0 )
    return mlo_mgr_link_switch_set_mac_addr_resp();
  if ( (v1 & 0x4000000) != 0 )
    return mlo_mgr_link_reject_set_mac_addr_resp();
  if ( (v1 & 0x8000000) != 0 )
    return mlo_link_recfg_set_mac_addr_resp();
  return mlme_vdev_mgr_notify_set_mac_addr_response();
}
