__int64 __fastcall cds_get_driver_state(
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
    return *(unsigned int *)(gp_cds_context + 16);
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: global cds context is NULL",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "cds_get_driver_state",
    v8,
    v9);
  return 0;
}
