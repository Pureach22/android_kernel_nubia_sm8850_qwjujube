__int64 ipa_disable_clks_v3_0()
{
  __int64 result; // x0
  __int64 v1; // x19
  __int64 v2; // x0

  result = ipa3_uc_notify_clk_state(0);
  v1 = ipa3_clk;
  if ( ipa3_clk )
  {
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d disabling gcc_ipa_clk\n", "_ipa_disable_clks_v3_0", 6764);
        v1 = ipa3_clk;
      }
    }
    clk_disable(v1);
    return clk_unprepare(v1);
  }
  return result;
}
