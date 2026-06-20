__int64 __fastcall lim_print_he_channel_widths(
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
  unsigned __int64 v9; // x8

  v9 = *(_QWORD *)(a1 + 1);
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: HE width 0:%d 1:%d 2:%d 3:%d 4:%d 5:%d 6:%d",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "lim_print_he_channel_widths",
           (v9 >> 50) & 1,
           (v9 >> 51) & 1,
           (v9 >> 52) & 1,
           (v9 >> 53) & 1,
           (v9 >> 54) & 1,
           (v9 >> 55) & 1,
           HIBYTE(v9) & 1);
}
