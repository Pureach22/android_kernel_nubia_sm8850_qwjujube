__int64 ipa_inc_clients_enable_clks_on_wq()
{
  unsigned __int64 v0; // x27
  __int64 v1; // x1
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  ((void (*)(void))ipa3_enable_clks)();
  printk(&unk_3EBC3C, "ipa_inc_clients_enable_clks_on_wq");
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(
        v3,
        "ipa %s:%d unexpected clk access, clock on IPA to save reg",
        "ipa_inc_clients_enable_clks_on_wq",
        7156);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(
        v4,
        "ipa %s:%d unexpected clk access, clock on IPA to save reg",
        "ipa_inc_clients_enable_clks_on_wq",
        7156);
  }
  v5 = printk(&unk_3AED39, v1);
  __break(0x800u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return ipa3_panic_notifier(v5);
}
