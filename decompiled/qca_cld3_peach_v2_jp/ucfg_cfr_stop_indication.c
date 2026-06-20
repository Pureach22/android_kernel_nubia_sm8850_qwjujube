__int64 __fastcall ucfg_cfr_stop_indication(
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
  if ( a1 )
    return cfr_stop_indication(a1);
  qdf_trace_msg(0x6Au, 2u, "%s: null vdev", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_cfr_stop_indication");
  return 4;
}
