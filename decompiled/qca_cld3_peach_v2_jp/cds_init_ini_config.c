__int64 __fastcall cds_init_ini_config(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( !gp_cds_context )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: cds context pointer is null (via %s)",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "__cds_get_context",
             "cds_init_ini_config",
             v9,
             v10);
  *(_QWORD *)(gp_cds_context + 152) = result;
  return result;
}
