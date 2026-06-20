__int64 __fastcall hal_rx_print_pn_be(
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
  __int64 v9; // x20

  v9 = jiffies;
  if ( hal_rx_print_pn_be___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x46u,
               2u,
               "%s: PN number pn_95_64 0x%x pn_63_32 0x%x pn_31_0 0x%x",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "hal_rx_print_pn_be",
               *(_QWORD *)(result + 72),
               HIDWORD(*(_QWORD *)(result + 64)));
    hal_rx_print_pn_be___last_ticks = v9;
  }
  return result;
}
