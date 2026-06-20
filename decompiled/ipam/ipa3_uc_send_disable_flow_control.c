__int64 ipa3_uc_send_disable_flow_control()
{
  unsigned int v0; // w19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0

  _ReadStatusReg(SP_EL0);
  ipa3_inc_client_enable_clks();
  v0 = ipa3_uc_send_cmd_64b_param(0, 0, 15, 0, 0, 2500);
  if ( v0 )
  {
    printk(&unk_3CD369, "ipa3_uc_send_disable_flow_control");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d fail to disable flow control\n", "ipa3_uc_send_disable_flow_control", 1973);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d fail to disable flow control\n", "ipa3_uc_send_disable_flow_control", 1973);
    }
  }
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v0;
}
