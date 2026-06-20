__int64 __fastcall get_cds_sched_ctxt(
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

  result = gp_cds_sched_context;
  if ( !gp_cds_sched_context )
  {
    qdf_trace_msg(0x38u, 2u, "%s: !gp_cds_sched_context", a1, a2, a3, a4, a5, a6, a7, a8, "get_cds_sched_ctxt");
    return gp_cds_sched_context;
  }
  return result;
}
