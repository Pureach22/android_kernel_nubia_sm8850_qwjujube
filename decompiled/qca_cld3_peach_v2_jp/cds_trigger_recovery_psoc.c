__int64 __fastcall cds_trigger_recovery_psoc(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        int a10,
        __int64 a11,
        int a12)
{
  __int64 v12; // x8
  __int64 v13; // x1

  v12 = gp_cds_context;
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
             "__cds_trigger_recovery");
  *(_DWORD *)(gp_cds_context + 296) = a10;
  v13 = *(_QWORD *)(v12 + 288);
  _cds_recovery_caller = a11;
  dword_81CC60 = a12;
  return queue_work_on(32, v13, v12 + 240);
}
