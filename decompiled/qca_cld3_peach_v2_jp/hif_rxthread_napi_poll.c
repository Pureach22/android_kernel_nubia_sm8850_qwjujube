__int64 __fastcall hif_rxthread_napi_poll(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: This napi_poll should not be polled as we don't schedule it",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hif_rxthread_napi_poll");
  return 0;
}
