__int64 __fastcall wlan_hdd_is_mlo_connection(
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
  __int64 vdev_by_user; // x0
  __int64 v10; // x20
  char is_mlo_vdev; // w19
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: Invalid link_info";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_is_mlo_connection");
    is_mlo_vdev = 0;
    return is_mlo_vdev & 1;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 81, "wlan_hdd_is_mlo_connection");
  if ( !vdev_by_user )
  {
    v12 = "%s: invalid vdev";
    goto LABEL_6;
  }
  v10 = vdev_by_user;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, a2, a3, a4, a5, a6, a7, a8, a9);
  _hdd_objmgr_put_vdev_by_user(v10, 81, "wlan_hdd_is_mlo_connection");
  return is_mlo_vdev & 1;
}
