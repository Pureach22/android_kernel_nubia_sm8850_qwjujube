char *__fastcall wlan_cm_get_rrm_cap_ie_data(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *mac_context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  mac_context = sme_get_mac_context(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( mac_context )
    return (char *)mac_context + 20220;
  qdf_trace_msg(0x34u, 2u, "%s: mac_ctx is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "wlan_cm_get_rrm_cap_ie_data");
  return nullptr;
}
