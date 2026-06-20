__int64 __fastcall dp_txrx_ext_stats_request(
        __int64 a1,
        char a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x21
  int v14; // w5
  int v15; // w9
  int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( a2 || (v11 = *(_DWORD **)(a1 + 72)) == nullptr )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "dp_txrx_ext_stats_request");
    return 4;
  }
  else
  {
    dp_aggregate_pdev_stats(*(_QWORD **)(a1 + 72));
    v14 = *(_DWORD *)(a1 + 13536)
        + *(_DWORD *)(a1 + 13532)
        + *(_DWORD *)(a1 + 13528)
        + *(_DWORD *)(a1 + 13524)
        + *(_DWORD *)(a1 + 13520);
    *a3 = v11[142];
    a3[1] = v14;
    a3[2] = v11[126] + *(_DWORD *)(a1 + 18624);
    v15 = v11[126];
    a3[4] = v15;
    a3[3] = *(_DWORD *)(a1 + 18624);
    v16 = v11[127];
    a3[5] = v16;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: ext stats: tx_msdu_enq = %u, tx_msdu_overflow = %u, rx_mpdu_receive = %u, rx_mpdu_delivered = %u, rx_mpdu_miss"
      "ed = %u, rx_mpdu_error = %u",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_txrx_ext_stats_request",
      v16,
      v15);
    return 0;
  }
}
