__int64 __fastcall dp_mon_filter_reset_tx_mon_mode_2_0(
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
  _QWORD *v9; // x8
  const char *v10; // x2

  if ( result )
  {
    if ( *(_QWORD *)(result + 8) )
    {
      v9 = **(_QWORD ***)(*(_QWORD *)(result + 95560) + 39328LL);
      v9[89] = 0;
      v9[88] = 0;
      v9[87] = 0;
      v9[86] = 0;
      v9[85] = 0;
      v9[84] = 0;
      v9[83] = 0;
      v9[82] = 0;
      v9[81] = 0;
      v9[80] = 0;
      v9[79] = 0;
      v9[78] = 0;
      v9[77] = 0;
      v9[76] = 0;
      v9[75] = 0;
      v9[74] = 0;
      v9[73] = 0;
      v9[72] = 0;
      return result;
    }
    v10 = "%s: Soc Context is null";
  }
  else
  {
    v10 = "%s: pdev Context is null";
  }
  return qdf_trace_msg(0x73u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_reset_tx_mon_mode_2_0");
}
