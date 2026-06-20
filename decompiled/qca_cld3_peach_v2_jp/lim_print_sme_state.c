__int64 __fastcall lim_print_sme_state(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  const char *v13; // x4

  if ( a11 > 0x10 )
    v13 = "INVALID SME STATE";
  else
    v13 = off_A0A4F0[a11];
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: SME state: %s",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_print_sme_state",
           v13,
           v11,
           v12);
}
