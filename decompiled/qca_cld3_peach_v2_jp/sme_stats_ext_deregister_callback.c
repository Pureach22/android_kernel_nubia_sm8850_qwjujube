__int64 __fastcall sme_stats_ext_deregister_callback(
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

  if ( !result )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid mac context",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "sme_stats_ext_register_callback",
             v9,
             v10);
  *(_QWORD *)(result + 13016) = 0;
  return result;
}
