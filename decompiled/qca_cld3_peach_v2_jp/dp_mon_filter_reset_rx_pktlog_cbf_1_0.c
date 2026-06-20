__int64 __fastcall dp_mon_filter_reset_rx_pktlog_cbf_1_0(
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
  __int64 v9; // x8
  __int64 v10; // x9
  bool v11; // zf
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  const char *v15; // x2

  if ( !result )
  {
    v15 = "%s: pdev Context is null";
    return qdf_trace_msg(0x73u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_rx_pktlog_cbf_1_0");
  }
  v9 = *(_QWORD *)(result + 8);
  if ( !v9 )
  {
    v15 = "%s: Soc Context is null";
    return qdf_trace_msg(0x73u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_rx_pktlog_cbf_1_0");
  }
  v10 = *(_QWORD *)(result + 95560);
  v11 = *(_BYTE *)(*(_QWORD *)(v9 + 40) + 633LL) == 0;
  v12 = 184;
  if ( v11 )
    v12 = 0;
  v13 = *(_QWORD *)(*(_QWORD *)(v10 + 37064) + 24LL) + v12;
  *(_DWORD *)(v13 + 88) = 0;
  *(_QWORD *)(v13 + 72) = 0;
  *(_QWORD *)(v13 + 80) = 0;
  *(_QWORD *)(v13 + 56) = 0;
  *(_QWORD *)(v13 + 64) = 0;
  *(_QWORD *)(v13 + 40) = 0;
  *(_QWORD *)(v13 + 48) = 0;
  *(_QWORD *)(v13 + 24) = 0;
  *(_QWORD *)(v13 + 32) = 0;
  *(_QWORD *)(v13 + 8) = 0;
  *(_QWORD *)(v13 + 16) = 0;
  *(_QWORD *)v13 = 0;
  v14 = *(_QWORD *)(*(_QWORD *)(v10 + 37064) + 24LL);
  *(_DWORD *)(v14 + 180) = 0;
  *(_QWORD *)(v14 + 172) = 0;
  *(_QWORD *)(v14 + 164) = 0;
  *(_QWORD *)(v14 + 156) = 0;
  *(_QWORD *)(v14 + 148) = 0;
  *(_QWORD *)(v14 + 140) = 0;
  *(_QWORD *)(v14 + 132) = 0;
  *(_QWORD *)(v14 + 124) = 0;
  *(_QWORD *)(v14 + 116) = 0;
  *(_QWORD *)(v14 + 108) = 0;
  *(_QWORD *)(v14 + 100) = 0;
  *(_QWORD *)(v14 + 92) = 0;
  return result;
}
