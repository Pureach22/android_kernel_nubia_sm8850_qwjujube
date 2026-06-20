__int64 __fastcall wma_get_ini_handle(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
    return a1 + 3360;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid WMA handle (via %s)",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "__wma_validate_handle",
    "wma_get_ini_handle",
    v9,
    v10);
  return 0;
}
