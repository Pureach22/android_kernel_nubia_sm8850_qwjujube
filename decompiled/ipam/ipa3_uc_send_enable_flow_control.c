__int64 __fastcall ipa3_uc_send_enable_flow_control(unsigned __int16 a1, unsigned __int16 a2)
{
  int v3; // w20
  unsigned int v4; // w20
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0

  _ReadStatusReg(SP_EL0);
  v3 = a1 | (a2 << 16);
  ipa3_inc_client_enable_clks();
  v4 = ipa3_uc_send_cmd_64b_param(v3, 0, 13, 0, 0, 2500);
  if ( v4 )
  {
    printk(&unk_3B89CC, "ipa3_uc_send_enable_flow_control");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d fail to enable flow ctrl for 0x%x\n",
          "ipa3_uc_send_enable_flow_control",
          1957,
          a1);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d fail to enable flow ctrl for 0x%x\n",
          "ipa3_uc_send_enable_flow_control",
          1957,
          a1);
    }
  }
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v4;
}
