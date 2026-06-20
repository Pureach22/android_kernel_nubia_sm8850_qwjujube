__int64 __fastcall cds_deinit_ini_config(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0

  if ( !gp_cds_context )
    return qdf_trace_msg(
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
             "cds_deinit_ini_config");
  result = *(_QWORD *)(gp_cds_context + 152);
  *(_QWORD *)(gp_cds_context + 152) = 0;
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
