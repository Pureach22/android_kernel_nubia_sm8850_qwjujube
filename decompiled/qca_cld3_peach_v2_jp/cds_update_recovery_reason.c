__int64 __fastcall cds_update_recovery_reason(
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
             "%s: gp_cds_context is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cds_update_recovery_reason",
             v9,
             v10);
  *(_DWORD *)(gp_cds_context + 296) = result;
  return result;
}
