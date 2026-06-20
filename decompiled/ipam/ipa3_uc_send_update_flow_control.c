__int64 __fastcall ipa3_uc_send_update_flow_control(int a1, unsigned __int8 a2)
{
  unsigned int v4; // w20
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    ipa3_inc_client_enable_clks();
    v4 = ipa3_uc_send_cmd_64b_param(a1, a2, 14, 0, 0, 2500);
    if ( v4 )
    {
      printk(&unk_3C49F5, "ipa3_uc_send_update_flow_control");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d fail flowCtrl update mask = 0x%x add_del = 0x%x\n",
            "ipa3_uc_send_update_flow_control",
            1996,
            a1,
            a2);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(
            v11,
            "ipa %s:%d fail flowCtrl update mask = 0x%x add_del = 0x%x\n",
            "ipa3_uc_send_update_flow_control",
            1996,
            a1,
            a2);
      }
    }
    ipa3_dec_client_disable_clks();
  }
  else
  {
    printk(&unk_3C160D, "ipa3_uc_send_update_flow_control");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_15;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Err update flow control, mask = 0\n", "ipa3_uc_send_update_flow_control", 1985);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d Err update flow control, mask = 0\n", "ipa3_uc_send_update_flow_control", 1985);
      v4 = 0;
    }
    else
    {
LABEL_15:
      v4 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
