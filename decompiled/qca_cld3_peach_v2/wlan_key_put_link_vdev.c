__int64 __fastcall wlan_key_put_link_vdev(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
    return wlan_objmgr_vdev_release_ref(a1, a2, v12, v13, v14, v15, v16, v17, v18, v19, v20);
  else
    return _hdd_objmgr_put_vdev_by_user(a1, a2, "wlan_key_put_link_vdev");
}
