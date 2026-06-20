__int64 __fastcall dp_mon_filter_reset_rx_pkt_log_lite_1_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8

  if ( !result )
    return qdf_trace_msg(
             0x73u,
             2u,
             "%s: pdev Context is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_filter_reset_rx_pkt_log_lite_1_0",
             v9,
             v10);
  v11 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 96456) + 37064LL) + 16LL);
  *(_DWORD *)(v11 + 180) = 0;
  *(_QWORD *)(v11 + 172) = 0;
  *(_QWORD *)(v11 + 164) = 0;
  *(_QWORD *)(v11 + 156) = 0;
  *(_QWORD *)(v11 + 148) = 0;
  *(_QWORD *)(v11 + 140) = 0;
  *(_QWORD *)(v11 + 132) = 0;
  *(_QWORD *)(v11 + 124) = 0;
  *(_QWORD *)(v11 + 116) = 0;
  *(_QWORD *)(v11 + 108) = 0;
  *(_QWORD *)(v11 + 100) = 0;
  *(_QWORD *)(v11 + 92) = 0;
  return result;
}
