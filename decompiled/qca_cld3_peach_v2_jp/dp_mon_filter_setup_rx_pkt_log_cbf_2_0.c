__int64 __fastcall dp_mon_filter_setup_rx_pkt_log_cbf_2_0(
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
  __int64 v9; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x20
  int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x9
  __int64 result; // x0
  const char *v32; // x2
  _QWORD src[19]; // [xsp+8h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v32 = "%s: pdev Context is null";
LABEL_8:
    result = qdf_trace_msg(0x73u, 2u, v32, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_rx_pkt_log_cbf_2_0");
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 95560);
  if ( !v9 )
  {
    v32 = "%s: Monitor pdev context is null";
    goto LABEL_8;
  }
  LOBYTE(src[0]) = 1;
  dp_mon_filter_set_status_cbf(a1, (__int64)src);
  dp_mon_filter_show_rx_filter_be(3u, (unsigned __int8 *)src, v11, v12, v13, v14, v15, v16, v17, v18);
  memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v9 + 39328) + 24LL) + 432LL), src, 0x90u);
  qdf_mem_set(src, 0x90u, 0);
  v19 = *(_QWORD *)(a1 + 8);
  v20 = *(_QWORD *)(a1 + 95560);
  LOBYTE(src[0]) = 1;
  v21 = *(unsigned __int8 *)(*(_QWORD *)(v19 + 40) + 633LL);
  dp_mon_filter_set_cbf_cmn(a1, (__int64)src);
  *(_QWORD *)((char *)src + 4) &= ~0x40uLL;
  dp_mon_filter_show_rx_filter_be(3u, (unsigned __int8 *)src, v22, v23, v24, v25, v26, v27, v28, v29);
  v30 = 288;
  if ( !v21 )
    v30 = 0;
  result = (__int64)memcpy((void *)(*(_QWORD *)(*(_QWORD *)(v20 + 39328) + 24LL) + v30), src, 0x90u);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
