__int64 __fastcall wlan_hdd_soc_set_antenna_mode_cb(
        unsigned int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19

  qdf_trace_msg(0x33u, 8u, "%s: Status: %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_soc_set_antenna_mode_cb", a1);
  v11 = osif_request_get(a2);
  if ( !v11 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: obsolete request",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wlan_hdd_soc_set_antenna_mode_cb");
  v20 = v11;
  osif_request_complete(v11);
  return osif_request_put(v20);
}
