__int64 __fastcall _cds_trigger_recovery(
        int a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x1

  v11 = gp_cds_context;
  if ( !gp_cds_context )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: gp_cds_context is null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "__cds_trigger_recovery");
  *(_DWORD *)(gp_cds_context + 296) = a1;
  _cds_recovery_caller = a2;
  v12 = *(_QWORD *)(v11 + 288);
  dword_81CC60 = a3;
  return queue_work_on(32, v12, v11 + 240);
}
