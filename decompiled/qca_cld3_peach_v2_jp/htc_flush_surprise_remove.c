__int64 __fastcall htc_flush_surprise_remove(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x11
  int v6; // w12

  if ( (dword_B0B4 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: +htc_flush_surprise_remove\n", "htc_flush_surprise_remove");
  htc_flush_rx_hold_queue(a1, a1 + 8);
  htc_flush_endpoint_tx(a1, a1 + 8, 0);
  htc_flush_rx_hold_queue(a1, a1 + 336);
  htc_flush_endpoint_tx(a1, a1 + 336, 0);
  htc_flush_rx_hold_queue(a1, a1 + 664);
  htc_flush_endpoint_tx(a1, a1 + 664, 0);
  htc_flush_rx_hold_queue(a1, a1 + 992);
  htc_flush_endpoint_tx(a1, a1 + 992, 0);
  htc_flush_rx_hold_queue(a1, a1 + 1320);
  htc_flush_endpoint_tx(a1, a1 + 1320, 0);
  htc_flush_rx_hold_queue(a1, a1 + 1648);
  htc_flush_endpoint_tx(a1, a1 + 1648, 0);
  htc_flush_rx_hold_queue(a1, a1 + 1976);
  htc_flush_endpoint_tx(a1, a1 + 1976, 0);
  htc_flush_rx_hold_queue(a1, a1 + 2304);
  htc_flush_endpoint_tx(a1, a1 + 2304, 0);
  htc_flush_rx_hold_queue(a1, a1 + 2632);
  htc_flush_endpoint_tx(a1, a1 + 2632, 0);
  result = hif_flush_surprise_remove();
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = a1 + v4;
    v4 += 328;
    *(_WORD *)(v5 + 12) = 0;
    *(_QWORD *)(v5 + 112) = v5 + 112;
    *(_QWORD *)(v5 + 120) = v5 + 112;
    *(_QWORD *)(v5 + 232) = v5 + 232;
    *(_QWORD *)(v5 + 240) = v5 + 232;
    *(_QWORD *)(v5 + 136) = 0;
    *(_DWORD *)(v5 + 8) = v3++;
    *(_DWORD *)(v5 + 128) = 0;
    *(_DWORD *)(v5 + 248) = 0;
    *(_QWORD *)(v5 + 256) = v5 + 256;
    *(_QWORD *)(v5 + 264) = v5 + 256;
    *(_DWORD *)(v5 + 272) = 0;
    *(_QWORD *)(v5 + 288) = a1;
    v6 = htc_credit_flow;
    *(_QWORD *)(v5 + 328) = 0;
    *(_BYTE *)(v5 + 308) = v6 != 0;
    *(_DWORD *)(v5 + 284) = 0;
  }
  while ( v4 != 2952 );
  if ( (dword_B0B4 & 8) != 0 )
    return qdf_trace_msg(56, 2, "%s: -htc_flush_surprise_remove\n", "htc_flush_surprise_remove");
  return result;
}
