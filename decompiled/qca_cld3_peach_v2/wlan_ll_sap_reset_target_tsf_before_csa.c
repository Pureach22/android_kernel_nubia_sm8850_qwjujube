__int64 __fastcall wlan_ll_sap_reset_target_tsf_before_csa(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
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

  if ( a10 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a10, 0x34u);
    if ( comp_private_obj )
    {
      *(_QWORD *)(comp_private_obj + 16) = 0;
      *(_QWORD *)(comp_private_obj + 24) = 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a1, a2, a3, a4, a5, a6, a7, a8, "ll_sap_get_vdev_priv_obj");
  }
  qdf_trace_msg(
    0xA1u,
    2u,
    "%s: vdev %d ll_sap obj null",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_ll_sap_reset_target_tsf_before_csa",
    *(unsigned __int8 *)(a10 + 168));
  return 4;
}
