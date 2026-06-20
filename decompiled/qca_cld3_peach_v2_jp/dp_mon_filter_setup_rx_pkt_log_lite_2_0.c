__int64 __fastcall dp_mon_filter_setup_rx_pkt_log_lite_2_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  const char *v20; // x2
  _QWORD src[19]; // [xsp+8h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v20 = "%s: pdev Context is null";
LABEL_6:
    result = qdf_trace_msg(0x73u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_rx_pkt_log_lite_2_0");
    goto LABEL_7;
  }
  v9 = *(_QWORD *)(a1 + 95560);
  if ( !v9 )
  {
    v20 = "%s: Monitor pdev context is null";
    goto LABEL_6;
  }
  v10 = *(_QWORD *)(a1 + 95560);
  LOBYTE(src[0]) = 1;
  dp_mon_filter_set_status_cmn(v10, (__int64)src);
  dp_mon_filter_show_rx_filter_be(2u, (unsigned __int8 *)src, v11, v12, v13, v14, v15, v16, v17, v18);
  result = (__int64)memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v9 + 39328) + 16LL) + 432LL), src, 0x90u);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
