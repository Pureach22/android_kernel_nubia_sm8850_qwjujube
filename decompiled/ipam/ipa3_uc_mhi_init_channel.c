__int64 __fastcall ipa3_uc_mhi_init_channel(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, char a4)
{
  char v4; // w22
  unsigned int v8; // w19
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_uc_mhi_ctx )
  {
    v4 = a1;
    if ( (a1 & 0x80000000) != 0 || *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3BE801, "ipa3_uc_mhi_init_channel");
      v10 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_12;
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Invalid ipa_ep_idx.\n", "ipa3_uc_mhi_init_channel", 711);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d Invalid ipa_ep_idx.\n", "ipa3_uc_mhi_init_channel", 711);
        v8 = -22;
      }
      else
      {
LABEL_12:
        v8 = -22;
      }
    }
    else
    {
      ipa3_inc_client_enable_clks();
      *(_BYTE *)ipa3_uc_mhi_ctx = 32;
      *(_DWORD *)(ipa3_uc_mhi_ctx + 4) = (a2 << 8) | 2;
      v8 = ipa3_uc_send_cmd(
             (unsigned __int16)(a3 << 8) | ((v4 & 0x3F) << 16) & 0xFF3FFF00 | ((a4 & 3) << 22) | a2,
             0x21u,
             0,
             0,
             250);
      if ( v8 )
      {
        printk(&unk_3D039E, "ipa3_uc_mhi_init_channel");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_channel", 733, v8);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_channel", 733, v8);
        }
      }
      ipa3_dec_client_disable_clks();
    }
  }
  else
  {
    printk(&unk_3B8A54, "ipa3_uc_mhi_init_channel");
    v13 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_23;
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_init_channel", 706);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_init_channel", 706);
      v8 = -14;
    }
    else
    {
LABEL_23:
      v8 = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
