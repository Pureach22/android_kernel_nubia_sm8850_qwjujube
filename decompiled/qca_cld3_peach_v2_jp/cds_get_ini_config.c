__int64 __fastcall cds_get_ini_config(
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

  if ( gp_cds_context )
    return *(_QWORD *)(gp_cds_context + 152);
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: cds context pointer is null (via %s)",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "__cds_get_context",
    "cds_get_ini_config",
    v8,
    v9);
  return 0;
}
