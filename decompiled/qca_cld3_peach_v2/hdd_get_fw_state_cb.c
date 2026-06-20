__int64 __fastcall hdd_get_fw_state_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_get_fw_state_cb");
  v10 = osif_request_get(a1);
  if ( !v10 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Obsolete request",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "hdd_get_fw_state_cb");
  v19 = v10;
  *(_BYTE *)osif_request_priv(v10) = 1;
  osif_request_complete(v19);
  return osif_request_put(v19);
}
