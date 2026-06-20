__int64 __fastcall dp_mon_filter_reset_rx_mon_mode_2_0(
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
  __int64 result; // x0
  const char *v11; // x2
  _QWORD src[19]; // [xsp+8h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v11 = "%s: pdev Context is null";
LABEL_8:
    result = qdf_trace_msg(0x73u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_rx_mon_mode_2_0");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v11 = "%s: Soc Context is null";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 95560);
  if ( !v9 )
  {
    v11 = "%s: mon_pdev Context is null";
    goto LABEL_8;
  }
  LOBYTE(src[0]) = 1;
  qdf_mem_set(src, 0x5Cu, 0);
  result = (__int64)memcpy((void *)(**(_QWORD **)(v9 + 39328) + 432LL), src, 0x90u);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
