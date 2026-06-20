__int64 __fastcall ipa3_uc_mhi_stop_event_update_channel(unsigned __int8 a1)
{
  unsigned int v2; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_uc_mhi_ctx )
  {
    ipa3_inc_client_enable_clks();
    *(_BYTE *)ipa3_uc_mhi_ctx = 37;
    *(_DWORD *)(ipa3_uc_mhi_ctx + 4) = a1;
    v2 = ipa3_uc_send_cmd(a1, 0x25u, 0, 0, 250);
    if ( v2 )
    {
      printk(&unk_3D039E, "ipa3_uc_mhi_stop_event_update_channel");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_stop_event_update_channel", 875, v2);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_stop_event_update_channel", 875, v2);
      }
    }
    ipa3_dec_client_disable_clks();
  }
  else
  {
    printk(&unk_3B8A54, "ipa3_uc_mhi_stop_event_update_channel");
    v4 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_15;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_stop_event_update_channel", 860);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_stop_event_update_channel", 860);
      v2 = -14;
    }
    else
    {
LABEL_15:
      v2 = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
