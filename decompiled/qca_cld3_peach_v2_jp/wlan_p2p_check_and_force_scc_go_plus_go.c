__int64 __fastcall wlan_p2p_check_and_force_scc_go_plus_go(
        __int64 a1,
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
  if ( a2 )
    return p2p_check_and_force_scc_go_plus_go(a1, a2);
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: vdev is NULL",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_p2p_check_and_force_scc_go_plus_go");
  return 4;
}
