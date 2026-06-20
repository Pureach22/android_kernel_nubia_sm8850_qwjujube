__int64 ipa3_enable_tx_suspend_wa()
{
  __int64 v0; // x0
  int reg_n; // w0
  __int64 v2; // x8
  int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d Enter\n", "ipa3_enable_tx_suspend_wa", 227);
  }
  ipa3_inc_client_enable_clks();
  reg_n = ipahal_read_reg_n(2, (unsigned int)ipa_ee);
  v2 = ipa3_ctx;
  v3 = reg_n;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(
        v4,
        "ipa %s:%d enable TX_SUSPEND_IRQ, IPA_IRQ_EN_EE reg, write val = %u\n",
        "ipa3_enable_tx_suspend_wa",
        244,
        v3 | 0x4000);
      v2 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v2 + 34160);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d enable TX_SUSPEND_IRQ, IPA_IRQ_EN_EE reg, write val = %u\n",
        "ipa3_enable_tx_suspend_wa",
        244,
        v3 | 0x4000);
      v2 = ipa3_ctx;
    }
  }
  if ( *(_BYTE *)(v2 + 43308) == 1 )
    ipa3_uc_rg10_write_reg(2, (unsigned int)ipa_ee, v3 | 0x4000u);
  else
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
      2,
      0,
      (unsigned int)ipa_ee,
      v3 | 0x4000u);
  ((void (__fastcall *)(_QWORD))ipa3_process_interrupts)(0);
  result = ipa3_dec_client_disable_clks();
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(result, "ipa %s:%d Exit\n", "ipa3_enable_tx_suspend_wa", 252);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
