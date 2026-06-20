__int64 ipa_enable_clks_v3_0()
{
  __int64 v0; // x0
  __int64 v1; // x8

  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d curr_ipa_clk_rate=%d", "_ipa_enable_clks_v3_0", 6683, *(_DWORD *)(ipa3_ctx + 34244));
  }
  if ( ipa3_clk )
  {
    if ( ipa3_ctx )
    {
      v1 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v1 )
        ipc_log_string(v1, "ipa %s:%d enabling gcc_ipa_clk\n", "_ipa_enable_clks_v3_0", 6685);
    }
    clk_prepare();
    clk_enable(ipa3_clk);
    clk_set_rate(ipa3_clk, *(unsigned int *)(ipa3_ctx + 34244));
  }
  return ipa3_uc_notify_clk_state(1);
}
