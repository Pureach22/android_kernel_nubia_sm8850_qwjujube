__int64 __fastcall cds_reset_recovery_reason(
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

  if ( !gp_cds_context )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: gp_cds_context is null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "cds_reset_recovery_reason",
             v8,
             v9);
  *(_DWORD *)(gp_cds_context + 296) = 0;
  return result;
}
