__int64 __fastcall dp_mon_filter_reset_rx_pktlog_cbf_2_0(
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
  __int64 v10; // x8
  int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  __int64 result; // x0
  const char *v22; // x2
  _QWORD src[19]; // [xsp+8h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v22 = "%s: pdev Context is null";
LABEL_8:
    result = qdf_trace_msg(0x73u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_rx_pktlog_cbf_2_0");
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 95560);
  if ( !v9 )
  {
    v22 = "%s: Monitor pdev context is null";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(a1 + 8);
  LOBYTE(src[0]) = 1;
  v11 = *(unsigned __int8 *)(*(_QWORD *)(v10 + 40) + 633LL);
  dp_mon_filter_set_cbf_cmn(a1, (__int64)src);
  *(_QWORD *)((char *)src + 4) &= ~0x40uLL;
  dp_mon_filter_show_rx_filter_be(3u, (unsigned __int8 *)src, v12, v13, v14, v15, v16, v17, v18, v19);
  v20 = 288;
  if ( !v11 )
    v20 = 0;
  memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v9 + 39328) + 24LL) + v20), src, 0x90u);
  result = (__int64)memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v9 + 39328) + 24LL) + 432LL), src, 0x90u);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
