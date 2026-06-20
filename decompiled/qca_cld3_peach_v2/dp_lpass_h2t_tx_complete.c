__int64 __fastcall dp_lpass_h2t_tx_complete(
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
           0x45u,
           5u,
           "%s: Unexpected lpass tx complete trigger",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "dp_lpass_h2t_tx_complete");
}
