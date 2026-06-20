__int64 __fastcall dp_mon_filter_reset_rx_pkt_log_full_2_0(
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
  _QWORD *v10; // x8
  const char *v11; // x2

  if ( result )
  {
    v9 = *(_QWORD *)(result + 95560);
    if ( v9 )
    {
      v10 = *(_QWORD **)(*(_QWORD *)(v9 + 39328) + 8LL);
      v10[71] = 0;
      v10[70] = 0;
      v10[69] = 0;
      v10[68] = 0;
      v10[67] = 0;
      v10[66] = 0;
      v10[65] = 0;
      v10[63] = 0;
      v10[64] = 0;
      v10[61] = 0;
      v10[62] = 0;
      v10[59] = 0;
      v10[60] = 0;
      v10[57] = 0;
      v10[58] = 0;
      v10[55] = 0;
      v10[56] = 0;
      v10[54] = 0;
      return result;
    }
    v11 = "%s: Monitor pdev context is null";
  }
  else
  {
    v11 = "%s: pdev Context is null";
  }
  return qdf_trace_msg(0x73u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_rx_pkt_log_full_2_0");
}
