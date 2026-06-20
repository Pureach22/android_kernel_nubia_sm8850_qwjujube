__int64 __fastcall lim_update_bss_he_capable(
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
  *(_BYTE *)(a10 + 301) = 1;
  return qdf_trace_msg(0x35u, 8u, "%s: he_capable: %d", a1, a2, a3, a4, a5, a6, a7, a8, "lim_update_bss_he_capable", 1);
}
