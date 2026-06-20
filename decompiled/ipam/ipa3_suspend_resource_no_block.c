__int64 __fastcall ipa3_suspend_resource_no_block(unsigned int a1)
{
  unsigned int v2; // w0
  __int64 v3; // x25
  unsigned int v4; // w20
  __int64 v5; // x24
  unsigned int ep_mapping; // w0
  unsigned int v7; // w22
  __int64 v8; // x8
  unsigned int v9; // w21
  char should_pipe_be_suspended; // w0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int16 v18[2]; // [xsp+20h] [xbp-230h] BYREF
  _DWORD s[135]; // [xsp+24h] [xbp-22Ch] BYREF
  __int64 v20; // [xsp+240h] [xbp-10h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  memset(s, 0, sizeof(s));
  v2 = ((__int64 (__fastcall *)(_QWORD, _DWORD *))ipa3_get_clients_from_rm_resource)(a1, s);
  if ( v2 )
  {
    v4 = v2;
    printk(&unk_3B2F3E, "ipa3_suspend_resource_no_block");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d ipa3_get_clients_from_rm_resource() failed, name = %d.\n",
          "ipa3_suspend_resource_no_block",
          7705,
          a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(
          v17,
          "ipa %s:%d ipa3_get_clients_from_rm_resource() failed, name = %d.\n",
          "ipa3_suspend_resource_no_block",
          7705,
          a1);
    }
  }
  else
  {
    if ( s[134] < 1 )
      goto LABEL_23;
    v3 = 0;
    v4 = 0;
    do
    {
      if ( v3 == 134 )
LABEL_30:
        __break(0x5512u);
      v5 = (unsigned int)s[v3];
      ep_mapping = ipa_get_ep_mapping((unsigned int)v5);
      if ( ep_mapping == -1 )
      {
        printk(&unk_3AC96C, "ipa3_suspend_resource_no_block");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d Invalid client.\n", "ipa3_suspend_resource_no_block", 7713);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d Invalid client.\n", "ipa3_suspend_resource_no_block", 7713);
        }
        v4 = -22;
      }
      else
      {
        if ( (unsigned int)v5 > 0x85 )
          goto LABEL_30;
        *(_BYTE *)(ipa3_ctx + v5 + 17500) = 0;
        if ( ep_mapping > 0x23 )
          goto LABEL_30;
        v7 = ep_mapping;
        v8 = ipa3_ctx;
        if ( *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 172) == (_DWORD)v5 )
        {
          v9 = ep_mapping;
          should_pipe_be_suspended = ipa3_should_pipe_be_suspended((unsigned int)v5);
          v8 = ipa3_ctx;
          if ( (should_pipe_be_suspended & 1) != 0 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 480LL * v7 + 168) )
            {
              v18[0] = 1;
              ipa_cfg_ep_ctrl(v9, (unsigned __int8 *)v18);
              v8 = ipa3_ctx;
            }
          }
        }
        if ( *(_DWORD *)(v8 + 480LL * v7 + 172) == (_DWORD)v5
          && (ipa3_should_pipe_channel_be_stopped((unsigned int)v5) & 1) != 0 )
        {
          v4 = -1;
          goto LABEL_24;
        }
      }
      ++v3;
    }
    while ( v3 < s[134] );
    if ( !v4 )
    {
LABEL_23:
      ipa_rm_resource_str(a1);
      *(_BYTE *)(ipa3_ctx + 31960) = 1;
      ipa3_dec_client_disable_clks_no_block();
      v4 = 0;
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v4;
}
