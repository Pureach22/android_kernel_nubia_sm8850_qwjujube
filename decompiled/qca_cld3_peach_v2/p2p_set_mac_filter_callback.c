__int64 __fastcall p2p_set_mac_filter_callback(
        char a1,
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
  char v10; // w19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20

  v10 = a1 & 1;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:set random mac filter result %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_set_mac_filter_callback",
    a1 & 1);
  v12 = osif_request_get(a2);
  if ( !v12 )
    return qdf_trace_msg(
             0x4Eu,
             2u,
             "%s: random_mac:invalid response",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "p2p_set_mac_filter_callback");
  v21 = v12;
  *(_BYTE *)osif_request_priv(v12) = v10;
  osif_request_complete(v21);
  return osif_request_put(v21);
}
