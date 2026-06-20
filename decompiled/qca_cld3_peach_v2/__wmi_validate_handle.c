__int64 __fastcall _wmi_validate_handle(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 )
    return 0;
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Invalid WMI handle (via %s)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "__wmi_validate_handle",
    a2,
    v10,
    v11);
  return 4294967274LL;
}
