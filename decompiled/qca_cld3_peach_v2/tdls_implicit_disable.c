__int64 __fastcall tdls_implicit_disable(
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
  qdf_trace_msg(0, 8u, "%s: Disable Implicit TDLS", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_implicit_disable");
  return tdls_timers_stop(a1);
}
