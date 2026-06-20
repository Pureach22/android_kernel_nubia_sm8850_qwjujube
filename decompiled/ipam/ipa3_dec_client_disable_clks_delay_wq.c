void __fastcall ipa3_dec_client_disable_clks_delay_wq(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0

  if ( (queue_delayed_work_on(
          32,
          *(_QWORD *)(ipa3_ctx + 31944),
          &ipa_dec_clients_disable_clks_on_suspend_irq_wq_work,
          a2)
      & 1) == 0 )
  {
    printk(&unk_3E595E, "ipa3_dec_client_disable_clks_delay_wq");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(
          v3,
          "ipa %s:%d Scheduling delayed work failed, disable clk\n",
          "ipa3_dec_client_disable_clks_delay_wq",
          7200);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(
          v4,
          "ipa %s:%d Scheduling delayed work failed, disable clk\n",
          "ipa3_dec_client_disable_clks_delay_wq",
          7200);
    }
    _ipa3_dec_client_disable_clks();
  }
}
