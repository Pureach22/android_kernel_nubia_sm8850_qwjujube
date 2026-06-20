__int64 ipa3_setup_tput_pipe()
{
  unsigned int ep_mapping; // w0
  signed int v1; // w19
  __int64 v2; // x20
  _QWORD *v3; // x20
  int v4; // t1
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w20
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  _QWORD v21[33]; // [xsp+18h] [xbp-108h] BYREF

  v21[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v21[25], 0, 56);
  memset(v21, 0, 192);
  v21[24] = 0x100000007DLL;
  ep_mapping = ipa_get_ep_mapping(125);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3AC96C, "ipa3_setup_tput_pipe");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Invalid client.\n", "ipa3_setup_tput_pipe", 1354);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Invalid client.\n", "ipa3_setup_tput_pipe", 1354);
        result = 4294967282LL;
        goto LABEL_7;
      }
    }
LABEL_18:
    result = 4294967282LL;
    goto LABEL_7;
  }
  v1 = ep_mapping;
  if ( ep_mapping >= 0x25 )
  {
    __break(0x5512u);
    JUMPOUT(0xA5C38);
  }
  v2 = ipa3_ctx + 480LL * (int)ep_mapping;
  v4 = *(_DWORD *)(v2 + 168);
  v3 = (_QWORD *)(v2 + 168);
  if ( v4 == 1 )
  {
    printk(&unk_3B202E, "ipa3_setup_tput_pipe");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d EP %d already allocated.\n", "ipa3_setup_tput_pipe", 1359, v1);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d EP %d already allocated.\n", "ipa3_setup_tput_pipe", 1359, v1);
        result = 4294967282LL;
        goto LABEL_7;
      }
    }
    goto LABEL_18;
  }
  ipa3_inc_client_enable_clks();
  memset(v3 + 1, 0, 0x1D0u);
  *v3 = 0x7D00000001LL;
  v5 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *))ipa_gsi_setup_channel)(v21, v3);
  if ( v5 )
  {
    v14 = v5;
    printk(&unk_3DB29B, "ipa3_setup_tput_pipe");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Failed to setup GSI channel\n", "ipa3_setup_tput_pipe", 1369);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d Failed to setup GSI channel\n", "ipa3_setup_tput_pipe", 1369);
    }
    goto LABEL_29;
  }
  v6 = ipa3_enable_data_path(v1);
  if ( v6 )
  {
    v14 = v6;
    printk(&unk_3AC989, "ipa3_setup_tput_pipe");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d enable data path failed res=%d ep=%d.\n", "ipa3_setup_tput_pipe", 1376, v14, v1);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d enable data path failed res=%d ep=%d.\n", "ipa3_setup_tput_pipe", 1376, v14, v1);
    }
LABEL_29:
    memset((void *)(ipa3_ctx + 480LL * v1 + 168), 0, 0x1E0u);
    ipa3_dec_client_disable_clks();
    result = v14;
    goto LABEL_7;
  }
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
