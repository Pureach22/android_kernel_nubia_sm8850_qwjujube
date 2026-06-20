__int64 __fastcall qdf_dp_unused(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  return qdf_trace_msg(
           0x38u,
           2u,
           "%s: %s: QDF_DP_TRACE_MAX event should not be generated",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "qdf_dp_unused",
           "qdf_dp_unused");
}
