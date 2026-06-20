__int64 __fastcall ipa3_suspend_resource_sync(unsigned int a1)
{
  unsigned int v2; // w0
  __int64 v3; // x26
  char v4; // w27
  __int64 v5; // x24
  unsigned int ep_mapping; // w0
  unsigned int v7; // w23
  __int64 v8; // x8
  char should_pipe_be_suspended; // w0
  unsigned int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int16 v22[2]; // [xsp+20h] [xbp-230h] BYREF
  _DWORD s[135]; // [xsp+24h] [xbp-22Ch] BYREF
  __int64 v24; // [xsp+240h] [xbp-10h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  memset(s, 0, sizeof(s));
  v2 = ((__int64 (__fastcall *)(_QWORD, _DWORD *))ipa3_get_clients_from_rm_resource)(a1, s);
  if ( v2 )
  {
    v18 = v2;
    printk(&unk_3EFCEC, "ipa3_suspend_resource_sync");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Bad params.\n", "ipa3_suspend_resource_sync", 7633);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d Bad params.\n", "ipa3_suspend_resource_sync", 7633);
    }
LABEL_32:
    result = v18;
  }
  else
  {
    if ( s[134] >= 1 )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        if ( v3 == 134 )
LABEL_38:
          __break(0x5512u);
        v5 = (unsigned int)s[v3];
        ep_mapping = ipa_get_ep_mapping((unsigned int)v5);
        if ( ep_mapping == -1 )
        {
          printk(&unk_3AC96C, "ipa3_suspend_resource_sync");
          v11 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v12 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v12 )
            {
              ipc_log_string(v12, "ipa %s:%d Invalid client.\n", "ipa3_suspend_resource_sync", 7641);
              v11 = ipa3_ctx;
            }
            v13 = *(_QWORD *)(v11 + 34160);
            if ( v13 )
              ipc_log_string(v13, "ipa %s:%d Invalid client.\n", "ipa3_suspend_resource_sync", 7641);
          }
        }
        else
        {
          if ( (unsigned int)v5 > 0x85 )
            goto LABEL_38;
          v7 = ep_mapping;
          *(_BYTE *)(ipa3_ctx + v5 + 17500) = 0;
          if ( ep_mapping > 0x23 )
            goto LABEL_38;
          v8 = ipa3_ctx;
          if ( *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 172) == (_DWORD)v5 )
          {
            should_pipe_be_suspended = ipa3_should_pipe_be_suspended((unsigned int)v5);
            v8 = ipa3_ctx;
            if ( (should_pipe_be_suspended & 1) != 0 )
            {
              if ( *(_DWORD *)(ipa3_ctx + 480LL * v7 + 168) )
              {
                v4 = 1;
                v22[0] = 1;
                ipa_cfg_ep_ctrl(v7, v22);
                v8 = ipa3_ctx;
              }
            }
          }
          if ( *(_DWORD *)(v8 + 480LL * v7 + 172) == (_DWORD)v5
            && (ipa3_should_pipe_channel_be_stopped((unsigned int)v5) & 1) != 0 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 480LL * v7 + 168) )
            {
              v10 = ipa_stop_gsi_channel(v7);
              if ( v10 )
              {
                v18 = v10;
                printk(&unk_3DC120, "ipa3_suspend_resource_sync");
                v19 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v20 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v20 )
                  {
                    ipc_log_string(
                      v20,
                      "ipa %s:%d failed stop gsi ch %lu\n",
                      "ipa3_suspend_resource_sync",
                      7664,
                      *(_QWORD *)(ipa3_ctx + 480LL * v7 + 176));
                    v19 = ipa3_ctx;
                  }
                  v21 = *(_QWORD *)(v19 + 34160);
                  if ( v21 )
                    ipc_log_string(
                      v21,
                      "ipa %s:%d failed stop gsi ch %lu\n",
                      "ipa3_suspend_resource_sync",
                      7664,
                      *(_QWORD *)(v19 + 480LL * v7 + 176));
                }
                goto LABEL_32;
              }
            }
          }
        }
        ++v3;
      }
      while ( v3 < s[134] );
      if ( (v4 & 1) != 0 )
        usleep_range_state(1000, 2000, 2);
    }
    *(_BYTE *)(ipa3_ctx + 31960) = 1;
    ipa_rm_resource_str(a1);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
