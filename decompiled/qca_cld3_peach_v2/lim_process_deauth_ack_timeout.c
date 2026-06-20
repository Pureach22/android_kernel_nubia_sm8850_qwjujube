__int64 __fastcall lim_process_deauth_ack_timeout(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Deauth Ack timeout for vdev id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_deauth_ack_timeout",
    a2);
  return lim_send_deauth_cnf(a1, a2);
}
