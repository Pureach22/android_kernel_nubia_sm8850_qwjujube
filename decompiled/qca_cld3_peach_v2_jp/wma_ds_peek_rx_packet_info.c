__int64 __fastcall wma_ds_peek_rx_packet_info(
        __int64 a1,
        _QWORD *a2,
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

  if ( a1 )
  {
    *a2 = a1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma:Invalid parameter sent on wma_peek_rx_pkt_info",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_ds_peek_rx_packet_info",
      v10,
      v11);
    return 5;
  }
}
