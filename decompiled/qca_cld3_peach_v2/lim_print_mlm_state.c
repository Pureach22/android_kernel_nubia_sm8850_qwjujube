__int64 __fastcall lim_print_mlm_state(
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

  if ( a11 > 0x1C )
    v13 = "INVALID MLM state";
  else
    v13 = off_AFC650[a11];
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: Mlm state: %s",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_print_mlm_state",
           v13,
           v11,
           v12);
}
