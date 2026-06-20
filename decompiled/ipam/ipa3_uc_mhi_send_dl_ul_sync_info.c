__int64 __fastcall ipa3_uc_mhi_send_dl_ul_sync_info(_DWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_uc_mhi_ctx )
  {
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(
          v3,
          "ipa %s:%d isDlUlSyncEnabled=0x%x UlAccmVal=0x%x\n",
          "ipa3_uc_mhi_send_dl_ul_sync_info",
          895,
          (unsigned __int8)*a1,
          BYTE1(*a1));
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d isDlUlSyncEnabled=0x%x UlAccmVal=0x%x\n",
          "ipa3_uc_mhi_send_dl_ul_sync_info",
          895,
          (unsigned __int8)*a1,
          BYTE1(*a1));
        v2 = ipa3_ctx;
      }
      if ( v2 )
      {
        v5 = *(_QWORD *)(v2 + 34152);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d ulMsiEventThreshold=0x%x dlMsiEventThreshold=0x%x\n",
            "ipa3_uc_mhi_send_dl_ul_sync_info",
            898,
            (unsigned __int8)BYTE2(*a1),
            HIBYTE(*a1));
          v2 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v2 + 34160);
        if ( v6 )
          ipc_log_string(
            v6,
            "ipa %s:%d ulMsiEventThreshold=0x%x dlMsiEventThreshold=0x%x\n",
            "ipa3_uc_mhi_send_dl_ul_sync_info",
            898,
            (unsigned __int8)BYTE2(*a1),
            HIBYTE(*a1));
      }
    }
    ipa3_inc_client_enable_clks();
    v7 = ipa3_uc_send_cmd((unsigned int)*a1, 0x24u, 0, 0, 250);
    if ( v7 )
    {
      printk(&unk_3D039E, "ipa3_uc_mhi_send_dl_ul_sync_info");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_send_dl_ul_sync_info", 905, v7);
          v12 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v12 + 34160);
        if ( v14 )
          ipc_log_string(v14, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_send_dl_ul_sync_info", 905, v7);
      }
    }
    ipa3_dec_client_disable_clks();
  }
  else
  {
    printk(&unk_3B8A54, "ipa3_uc_mhi_send_dl_ul_sync_info");
    v9 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_25;
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_send_dl_ul_sync_info", 890);
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_send_dl_ul_sync_info", 890);
      v7 = -14;
    }
    else
    {
LABEL_25:
      v7 = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
