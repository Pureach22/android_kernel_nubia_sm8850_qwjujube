__int64 __fastcall hdd_get_mld_mac_addr_from_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( *(_DWORD *)(a1 + 16) != 1 )
    return 0;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
    return *(_QWORD *)(a1 + 1360) + 17LL;
  return 0;
}
