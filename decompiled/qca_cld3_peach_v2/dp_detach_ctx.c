__int64 __fastcall dp_detach_ctx(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x29
  __int64 v9; // x30
  __int64 result; // x0

  if ( !gp_dp_ctx )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: global dp ctx is already detached",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "dp_detach_ctx",
             v8,
             v9);
  gp_dp_ctx = 0;
  return result;
}
