__int64 __fastcall ucfg_dp_rx_aggr_dis_req(
        __int64 a1,
        unsigned int a2,
        char a3,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( comp_private_obj )
      return wlan_dp_rx_aggr_dis_req(
               *(_QWORD *)(comp_private_obj + 32),
               a2,
               a3 & 1,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "dp_get_vdev_priv_obj");
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: DP link Null, vdev_id: %u client id:%u disable:%u",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           "ucfg_dp_rx_aggr_dis_req",
           *(unsigned __int8 *)(a1 + 104),
           a2,
           a3 & 1);
}
