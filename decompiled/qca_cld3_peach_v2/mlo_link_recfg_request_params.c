__int64 __fastcall mlo_link_recfg_request_params(
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a10 )
    return 0;
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Invalid params",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "mlo_link_recfg_request_params",
    v10,
    v11);
  return 4;
}
