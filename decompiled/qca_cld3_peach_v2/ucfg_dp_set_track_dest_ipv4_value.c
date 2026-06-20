__int64 __fastcall ucfg_dp_set_track_dest_ipv4_value(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( result )
    {
      *(_DWORD *)(*(_QWORD *)(result + 32) + 3352LL) = a2;
      return result;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: Unable to get DP link",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "ucfg_dp_set_track_dest_ipv4_value");
}
