__int64 __fastcall wma_process_update_membership(
        __int64 *a1,
        unsigned int *a2,
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
    0x36u,
    8u,
    "%s: membership = %x ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_process_update_membership",
    *a2);
  return wma_set_peer_param(a1, (__int64)a2 + 6, 7u, *a2, *((unsigned __int16 *)a2 + 2));
}
