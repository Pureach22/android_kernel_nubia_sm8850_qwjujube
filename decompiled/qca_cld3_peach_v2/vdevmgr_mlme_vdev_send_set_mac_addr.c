__int64 __fastcall vdevmgr_mlme_vdev_send_set_mac_addr(__int64 a1, __int64 a2)
{
  return vdev_mgr_send_set_mac_addr(a1 & 0xFFFFFFFFFFFFLL, a2 & 0xFFFFFFFFFFFFLL);
}
