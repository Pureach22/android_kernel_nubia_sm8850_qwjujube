__int64 __fastcall wma_log_pkt_ipv4(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned int v12; // w19
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a2 >= 0x2A )
  {
    v12 = *(unsigned __int16 *)(result + 16);
    v13 = result;
    qdf_trace_msg(
      0x36u,
      4u,
      "src addr %d:%d:%d:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      *(unsigned __int8 *)(result + 26),
      *(unsigned __int8 *)(result + 27),
      *(unsigned __int8 *)(result + 28),
      *(unsigned __int8 *)(result + 29),
      v10,
      v11);
    qdf_trace_msg(
      0x36u,
      4u,
      "dst addr %d:%d:%d:%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      *(unsigned __int8 *)(v13 + 30),
      *(unsigned __int8 *)(v13 + 31),
      *(unsigned __int8 *)(v13 + 32),
      *(unsigned __int8 *)(v13 + 33));
    return qdf_trace_msg(
             0x36u,
             8u,
             "%s: Pkt_len: %u, src_port: %u, dst_port: %u",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "wma_log_pkt_ipv4",
             bswap32(v12) >> 16,
             bswap32(*(unsigned __int16 *)(v13 + 34)) >> 16,
             bswap32(*(unsigned __int16 *)(v13 + 36)) >> 16);
  }
  return result;
}
