__int64 __fastcall lim_remove_puncture(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( *(_WORD *)(a2 + 7184) )
  {
    v10 = result;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Remove puncture from reg: bitmap 0x%x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_remove_puncture");
    return wlan_reg_remove_puncture(*(_QWORD *)(v10 + 21632), v11, v12, v13, v14, v15, v16, v17, v18);
  }
  return result;
}
