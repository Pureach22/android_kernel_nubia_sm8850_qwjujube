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
  const char *v10; // x2

  if ( !a1 )
  {
    v10 = "%s: Invalid link_info";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_is_mlo_connection");
    return 0;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 81, "wlan_hdd_is_mlo_connection");
  if ( !vdev_by_user )
  {
    v10 = "%s: invalid vdev";
    goto LABEL_6;
  }
  _hdd_objmgr_put_vdev_by_user(vdev_by_user, 81, "wlan_hdd_is_mlo_connection");
  return 0;
}
