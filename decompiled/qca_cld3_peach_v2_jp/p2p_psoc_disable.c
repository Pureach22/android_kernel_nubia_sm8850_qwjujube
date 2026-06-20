__int64 __fastcall p2p_psoc_disable(
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
    return ucfg_p2p_psoc_stop(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(0x48u, 2u, "%s: psoc null", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_psoc_disable");
  return 4;
}
