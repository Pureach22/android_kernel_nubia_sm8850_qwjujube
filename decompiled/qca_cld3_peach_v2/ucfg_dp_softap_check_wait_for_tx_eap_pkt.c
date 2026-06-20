__int64 __fastcall ucfg_dp_softap_check_wait_for_tx_eap_pkt(
        __int64 a1,
        unsigned __int8 *a2,
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

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( comp_private_obj )
      return dp_softap_check_wait_for_tx_eap_pkt(*(_QWORD *)(comp_private_obj + 32), a2);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: DP link not found",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "ucfg_dp_softap_check_wait_for_tx_eap_pkt");
}
