__int64 __fastcall lim_log_he_bss_color(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: countdown: %d, new_color: %d",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_log_he_bss_color",
           *(unsigned __int8 *)(a10 + 1),
           *(_BYTE *)(a10 + 2) & 0x3F);
}
