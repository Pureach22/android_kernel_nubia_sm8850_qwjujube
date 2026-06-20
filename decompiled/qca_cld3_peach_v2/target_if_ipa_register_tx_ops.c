__int64 __fastcall target_if_ipa_register_tx_ops(
        __int64 a1,
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

  if ( a1 )
  {
    *(_QWORD *)(a1 + 2088) = target_if_ipa_uc_offload_control_req;
    *(_QWORD *)(a1 + 2096) = target_if_ipa_intrabss_control_req;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_ipa_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
