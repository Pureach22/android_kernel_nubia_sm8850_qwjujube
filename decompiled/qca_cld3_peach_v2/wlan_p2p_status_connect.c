__int64 __fastcall wlan_p2p_status_connect(
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
  if ( a1 )
    return p2p_status_connect(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(0x4Eu, 2u, "%s: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_p2p_status_connect");
  return 4;
}
