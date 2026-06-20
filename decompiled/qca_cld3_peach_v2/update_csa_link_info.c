__int64 __fastcall update_csa_link_info(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  unsigned __int8 v13; // w19
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v12 = *(_QWORD *)(a1 + 216);
  if ( !v12 )
    return qdf_trace_msg(0x35u, 2u, "%s: pdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "update_csa_link_info");
  v13 = a2;
  v14 = *(unsigned __int8 *)(a1 + 168);
  mlo_mgr_update_csa_link_info(v12, *(_QWORD *)(a1 + 1360), a3, a2);
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: vdev_id: %d link id %d mlo csa sta param updated ",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           "update_csa_link_info",
           v14,
           v13);
}
