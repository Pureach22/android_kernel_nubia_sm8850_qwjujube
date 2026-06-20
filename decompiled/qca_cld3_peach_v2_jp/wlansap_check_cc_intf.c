__int64 __fastcall wlansap_check_cc_intf(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
    return sme_check_concurrent_channel_overlap(context, *a1, a1[371]);
  qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v11, v12, v13, v14, v15, v16, v17, v18, "wlansap_check_cc_intf");
  return 0;
}
