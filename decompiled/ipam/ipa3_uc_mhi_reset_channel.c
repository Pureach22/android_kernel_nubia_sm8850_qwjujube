__int64 __fastcall ipa3_uc_mhi_reset_channel(unsigned __int8 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_uc_mhi_ctx )
  {
    ipa3_inc_client_enable_clks();
    v2 = a1 << 8;
    *(_BYTE *)ipa3_uc_mhi_ctx = 32;
    *(_DWORD *)(ipa3_uc_mhi_ctx + 4) = v2;
    v3 = ipa3_uc_send_cmd(v2, 0x23u, 0, 0, 250);
    if ( v3 )
    {
      printk(&unk_3D039E, "ipa3_uc_mhi_reset_channel");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_reset_channel", 770, v3);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_reset_channel", 770, v3);
      }
    }
    ipa3_dec_client_disable_clks();
  }
  else
  {
    printk(&unk_3B8A54, "ipa3_uc_mhi_reset_channel");
    v5 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_15;
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_reset_channel", 752);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_reset_channel", 752);
      v3 = -14;
    }
    else
    {
LABEL_15:
      v3 = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
