__int64 __fastcall ipa3_resume_resource(unsigned int a1)
{
  unsigned int v2; // w0
  __int64 v3; // x27
  unsigned int started; // w19
  __int64 v5; // x24
  unsigned int ep_mapping; // w0
  unsigned int v7; // w25
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  char should_pipe_be_suspended; // w0
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // t1
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned __int8 v26[4]; // [xsp+0h] [xbp-230h] BYREF
  _DWORD s[135]; // [xsp+4h] [xbp-22Ch] BYREF
  __int64 v28; // [xsp+220h] [xbp-10h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)v26 = 0;
  memset(s, 0, sizeof(s));
  v2 = ((__int64 (__fastcall *)(_QWORD, _DWORD *))ipa3_get_clients_from_rm_resource)(a1, s);
  if ( !v2 )
  {
    if ( s[134] < 1 )
    {
      started = 0;
      goto LABEL_30;
    }
    v3 = 0;
    started = 0;
    while ( 1 )
    {
      if ( v3 == 134 )
LABEL_41:
        __break(0x5512u);
      v5 = (unsigned int)s[v3];
      ep_mapping = ipa_get_ep_mapping((unsigned int)v5);
      if ( ep_mapping == -1 )
      {
        printk(&unk_3AC96C, "ipa3_resume_resource");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d Invalid client.\n", "ipa3_resume_resource", 7775);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d Invalid client.\n", "ipa3_resume_resource", 7775);
        }
        started = -22;
      }
      else
      {
        if ( (unsigned int)v5 > 0x85 )
          goto LABEL_41;
        v7 = ep_mapping;
        *(_BYTE *)(ipa3_ctx + v5 + 17500) = 1;
        v8 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v9 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v9 )
          {
            ipc_log_string(v9, "ipa %s:%d %d will be resumed on connect.\n", "ipa3_resume_resource", 7784, v5);
            v8 = ipa3_ctx;
          }
          v10 = *(_QWORD *)(v8 + 34160);
          if ( v10 )
            ipc_log_string(v10, "ipa %s:%d %d will be resumed on connect.\n", "ipa3_resume_resource", 7784, v5);
        }
        if ( v7 > 0x23 )
          goto LABEL_41;
        v11 = ipa3_ctx;
        if ( *(_DWORD *)(ipa3_ctx + 480LL * v7 + 172) == (_DWORD)v5 )
        {
          should_pipe_be_suspended = ipa3_should_pipe_be_suspended((unsigned int)v5);
          v11 = ipa3_ctx;
          if ( (should_pipe_be_suspended & 1) != 0 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 480LL * v7 + 168) )
            {
              *(_WORD *)v26 = 0;
              ipa_cfg_ep_ctrl(v7, v26);
              v11 = ipa3_ctx;
            }
          }
        }
        if ( *(_DWORD *)(v11 + 480LL * v7 + 172) == (_DWORD)v5
          && (ipa3_should_pipe_channel_be_stopped((unsigned int)v5) & 1) != 0 )
        {
          v13 = ipa3_ctx + 480LL * v7;
          v15 = *(_DWORD *)(v13 + 168);
          v14 = v13 + 168;
          if ( v15 )
          {
            started = gsi_start_channel(*(_QWORD *)(v14 + 8));
            if ( started )
            {
              printk(&unk_3CA606, "ipa3_resume_resource");
              v23 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v24 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v24 )
                {
                  ipc_log_string(
                    v24,
                    "ipa %s:%d failed to start gsi ch %lu\n",
                    "ipa3_resume_resource",
                    7801,
                    *(_QWORD *)(ipa3_ctx + 480LL * v7 + 176));
                  v23 = ipa3_ctx;
                }
                v25 = *(_QWORD *)(v23 + 34160);
                if ( v25 )
                  ipc_log_string(
                    v25,
                    "ipa %s:%d failed to start gsi ch %lu\n",
                    "ipa3_resume_resource",
                    7801,
                    *(_QWORD *)(v23 + 480LL * v7 + 176));
              }
              goto LABEL_30;
            }
          }
        }
      }
      if ( ++v3 >= s[134] )
        goto LABEL_30;
    }
  }
  started = v2;
  printk(&unk_3BE9D9, "ipa3_resume_resource");
  v20 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v21 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d ipa3_get_clients_from_rm_resource() failed.\n", "ipa3_resume_resource", 7767);
      v20 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v20 + 34160);
    if ( v22 )
      ipc_log_string(v22, "ipa %s:%d ipa3_get_clients_from_rm_resource() failed.\n", "ipa3_resume_resource", 7767);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return started;
}
