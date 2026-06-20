__int64 __fastcall reg_print_ap_power_type_6ghz(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v9; // x3

  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      v9 = "VERY LOW POWER INDOOR";
      return qdf_trace_msg(0x31u, 8u, "AP Power type %s", a2, a3, a4, a5, a6, a7, a8, a9, v9);
    }
    if ( a1 == 3 )
    {
      v9 = "INDOOR_ENABLED_AP";
      return qdf_trace_msg(0x31u, 8u, "AP Power type %s", a2, a3, a4, a5, a6, a7, a8, a9, v9);
    }
    return qdf_trace_msg(0x31u, 8u, "Invalid AP Power type %u", a2, a3, a4, a5, a6, a7, a8, a9);
  }
  if ( !a1 )
  {
    v9 = "LOW POWER INDOOR";
    return qdf_trace_msg(0x31u, 8u, "AP Power type %s", a2, a3, a4, a5, a6, a7, a8, a9, v9);
  }
  if ( a1 != 1 )
    return qdf_trace_msg(0x31u, 8u, "Invalid AP Power type %u", a2, a3, a4, a5, a6, a7, a8, a9);
  v9 = "STANDARD POWER";
  return qdf_trace_msg(0x31u, 8u, "AP Power type %s", a2, a3, a4, a5, a6, a7, a8, a9, v9);
}
