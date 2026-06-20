void ipa3_interrupt_defer()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  _QWORD v6[4]; // [xsp+0h] [xbp-20h] BYREF

  v6[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d processing interrupts in wq\n", "ipa3_interrupt_defer", 390);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d processing interrupts in wq\n", "ipa3_interrupt_defer", 390);
  }
  ipa3_inc_client_enable_clks();
  ((void (__fastcall *)(_QWORD))ipa3_process_interrupts)(0);
  v6[0] = "ipa3_interrupt_defer";
  v6[1] = "ipa_interrupts.c";
  v6[2] = 0x100000189LL;
  ipa3_dec_client_disable_clks_delay_wq((__int64)v6, 2);
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d Done\n", "ipa3_interrupt_defer", 396);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Done\n", "ipa3_interrupt_defer", 396);
  }
  _ReadStatusReg(SP_EL0);
}
