__int64 __fastcall wlan_vdev_mlme_send_set_mac_addr(__int64 a1, __int64 a2)
{
  return mlme_vdev_ops_send_set_mac_address(a1 & 0xFFFFFFFFFFFFLL, a2 & 0xFFFFFFFFFFFFLL);
}
