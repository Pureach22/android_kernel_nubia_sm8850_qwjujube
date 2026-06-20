__int64 __fastcall ipa3_uc_mhi_resume_channel(unsigned __int8 a1, char a2)
{
  int v4; // w10
  int v5; // w8
  unsigned int v6; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_uc_mhi_ctx )
  {
    ipa3_inc_client_enable_clks();
    v4 = (a1 << 8) | 2;
    *(_BYTE *)ipa3_uc_mhi_ctx = 32;
    *(_DWORD *)(ipa3_uc_mhi_ctx + 4) = v4;
    if ( (a2 & 1) != 0 )
      v5 = 0x10000;
    else
      v5 = 0;
    v6 = ipa3_uc_send_cmd(v4 | (unsigned int)v5, 0x23u, 0, 0, 250);
    if ( v6 )
    {
      printk(&unk_3D039E, "ipa3_uc_mhi_resume_channel");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_resume_channel", 843, v6);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_resume_channel", 843, v6);
      }
    }
    ipa3_dec_client_disable_clks();
  }
  else
  {
    printk(&unk_3B8A54, "ipa3_uc_mhi_resume_channel");
    v8 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_18;
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_resume_channel", 824);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_resume_channel", 824);
      v6 = -14;
    }
    else
    {
LABEL_18:
      v6 = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
