__int64 __fastcall dp_attach_ctx(
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
  __int64 v9; // x19

  v9 = result;
  if ( gp_dp_ctx )
    result = qdf_trace_msg(
               0x45u,
               8u,
               "%s: already attached global dp ctx",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dp_attach_ctx");
  gp_dp_ctx = v9;
  return result;
}
