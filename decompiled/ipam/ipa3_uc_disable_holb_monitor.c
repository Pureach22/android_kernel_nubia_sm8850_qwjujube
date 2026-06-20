__int64 ipa3_uc_disable_holb_monitor()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  unsigned int v3; // w19

  _ReadStatusReg(SP_EL0);
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(
        v1,
        "ipa %s:%d Sending uc IPA_CPU_2_HW_CMD_DISABLE_HOLB_MONITOR\n",
        "ipa3_uc_disable_holb_monitor",
        1408);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(
        v2,
        "ipa %s:%d Sending uc IPA_CPU_2_HW_CMD_DISABLE_HOLB_MONITOR\n",
        "ipa3_uc_disable_holb_monitor",
        1408);
  }
  ipa3_inc_client_enable_clks();
  v3 = ipa3_uc_send_cmd_64b_param(0, 0, 20, 0, 0, 2500);
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v3;
}
