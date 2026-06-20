__int64 __fastcall wlan_vdev_get_tdls_vdev_obj(
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
  if ( a1 )
    return wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
  qdf_trace_msg(0, 2u, "%s: NULL vdev", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_get_tdls_vdev_obj");
  return 0;
}
