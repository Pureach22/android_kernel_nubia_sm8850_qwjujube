__int64 __fastcall wlan_vdev_mlme_get_ext_hdl(
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
  __int64 comp_private_obj; // x0
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( comp_private_obj )
      return *(_QWORD *)(comp_private_obj + 520);
    v11 = "%s:  MLME component object is NULL";
  }
  else
  {
    v11 = "%s: vdev is NULL";
  }
  qdf_trace_msg(0x68u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_get_cmpt_obj");
  return 0;
}
