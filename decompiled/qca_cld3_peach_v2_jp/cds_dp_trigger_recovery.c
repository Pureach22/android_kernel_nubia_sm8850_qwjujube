__int64 __fastcall cds_dp_trigger_recovery(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x1

  v9 = gp_cds_context;
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
             "__cds_trigger_recovery");
  v10 = *(_QWORD *)(gp_cds_context + 288);
  *(_DWORD *)(gp_cds_context + 296) = a1;
  _cds_recovery_caller = (__int64)"cds_dp_trigger_recovery";
  dword_81CC60 = 136;
  return queue_work_on(32, v10, v9 + 240);
}
