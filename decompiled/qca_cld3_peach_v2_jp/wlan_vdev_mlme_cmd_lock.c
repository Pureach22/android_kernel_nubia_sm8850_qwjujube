__int64 __fastcall wlan_vdev_mlme_cmd_lock(
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
  __int64 result; // x0
  const char *v10; // x2
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( result )
      return result;
    v10 = "%s:  MLME component object is NULL";
  }
  else
  {
    v10 = "%s: vdev is NULL";
  }
  qdf_trace_msg(0x68u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_get_cmpt_obj");
  return qdf_trace_msg(
           0x68u,
           2u,
           "%s: vdev component object is NULL",
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           "wlan_vdev_mlme_cmd_lock");
}
