__int64 __fastcall wlan_is_tdls_session_present(
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
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( !(unsigned __int16)tdls_get_connected_peer_count_from_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
    return 4;
  qdf_trace_msg(
    0,
    8u,
    "%s: TDLS session is present",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wlan_is_tdls_session_present");
  return 0;
}
