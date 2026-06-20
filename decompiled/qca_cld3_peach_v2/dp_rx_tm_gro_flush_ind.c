__int64 __fastcall dp_rx_tm_gro_flush_ind(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w20
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v13 = a2 % (unsigned int)*a1;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: ring_num %d, selected thread %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_rx_tm_select_thread");
  v14 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8LL * v13);
  *(_DWORD *)(v14 + 416) = a3;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Flush indication received",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "dp_rx_tm_thread_gro_flush_ind");
  *(_QWORD *)(v14 + 424) |= 2uLL;
  _wake_up(v14 + 1136, 1, 1, 0);
  return 0;
}
