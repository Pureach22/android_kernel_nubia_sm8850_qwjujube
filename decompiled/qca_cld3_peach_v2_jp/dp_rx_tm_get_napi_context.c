__int64 __fastcall dp_rx_tm_get_napi_context(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w20

  v11 = a2 % (unsigned int)*a1;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: ring_num %d, selected thread %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_rx_tm_select_thread");
  return *(_QWORD *)(*((_QWORD *)a1 + 3) + 8LL * v11) + 704LL;
}
