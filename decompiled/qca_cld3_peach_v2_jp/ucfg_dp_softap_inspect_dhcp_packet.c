__int64 __fastcall ucfg_dp_softap_inspect_dhcp_packet(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( comp_private_obj )
      return dp_softap_inspect_dhcp_packet(comp_private_obj, a2, a3);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "dp_get_vdev_priv_obj");
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable to get DP link",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "ucfg_dp_softap_inspect_dhcp_packet");
  return 4;
}
