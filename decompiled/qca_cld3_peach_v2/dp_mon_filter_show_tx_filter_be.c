__int64 __fastcall dp_mon_filter_show_tx_filter_be(
        unsigned int a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0

  qdf_trace_msg(0x73u, 8u, "TX MON RING TLV FILTER CONFIG:", a3, a4, a5, a6, a7, a8, a9, a10);
  result = qdf_trace_msg(
             0x73u,
             8u,
             "[Mode %d]: Valid: %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             a1,
             *(unsigned __int8 *)(a2 + 140));
  if ( *(_BYTE *)(a2 + 140) == 1 )
    return dp_tx_mon_filter_show_filter(a2);
  return result;
}
