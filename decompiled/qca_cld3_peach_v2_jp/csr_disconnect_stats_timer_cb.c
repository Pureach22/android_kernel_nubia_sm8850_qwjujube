__int64 __fastcall csr_disconnect_stats_timer_cb(
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
  if ( !a1 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid mac ctx",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "csr_disconnect_stats_timer_cb");
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Disconnect peer stats timed out",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "csr_disconnect_stats_timer_cb");
  return csr_continue_peer_disconnect_after_get_stats(a1);
}
