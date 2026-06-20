__int64 __fastcall wma_set_keepalive_req(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  qdf_trace_msg(0x36u, 8u, "KEEPALIVE:PacketType:%d", a3, a4, a5, a6, a7, a8, a9, a10, *a2);
  wma_set_sta_keep_alive(
    a1,
    a2[28],
    *a2,
    *((_DWORD *)a2 + 1),
    a2 + 8,
    a2 + 12,
    a2 + 16,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19);
  return _qdf_mem_free((__int64)a2);
}
