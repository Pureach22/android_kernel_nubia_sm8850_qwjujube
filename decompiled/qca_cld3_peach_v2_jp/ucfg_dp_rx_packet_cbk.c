__int64 __fastcall ucfg_dp_rx_packet_cbk(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // x20

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( comp_private_obj )
      return dp_rx_packet_cbk(comp_private_obj, a2, v12, v13, v14, v15, v16, v17, v18, v19);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
  }
  v21 = jiffies;
  if ( ucfg_dp_rx_packet_cbk___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP link not found", v12, v13, v14, v15, v16, v17, v18, v19, "ucfg_dp_rx_packet_cbk");
    ucfg_dp_rx_packet_cbk___last_ticks = v21;
  }
  return 4;
}
