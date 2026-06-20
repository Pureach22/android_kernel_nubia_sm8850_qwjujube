__int64 ipa3_odl_pipe_open()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned int v15; // w21
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD v19[3]; // [xsp+8h] [xbp-18h] BYREF

  v19[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0xEu )
  {
    if ( (*(_WORD *)(ipa3_odl_ctx + 692) & 4) != 0 )
    {
      if ( *(_DWORD *)(ipa3_ctx + 45216) )
      {
        printk(&unk_3A3CBF, "ipa3_odl_pipe_open");
        v13 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_7;
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(
            v14,
            "ipa %s:%d SSR in progress ODL pipe configuration not allowed\n",
            "ipa3_odl_pipe_open",
            376);
          v13 = ipa3_ctx;
        }
        result = *(_QWORD *)(v13 + 34160);
        if ( result )
        {
          ipc_log_string(
            result,
            "ipa %s:%d SSR in progress ODL pipe configuration not allowed\n",
            "ipa3_odl_pipe_open",
            376);
          goto LABEL_7;
        }
      }
      else
      {
        v19[0] = 0;
        v19[1] = 0x100000000LL;
        v5 = ipa_setup_odl_pipe();
        if ( !v5 )
        {
          ipa3_cfg_ep_holb_by_client(83, v19);
          v6 = ipa3_ctx;
          *(_WORD *)(ipa3_odl_ctx + 692) |= 0x10u;
          if ( v6 )
          {
            v7 = *(_QWORD *)(v6 + 34152);
            if ( v7 )
            {
              ipc_log_string(v7, "ipa %s:%d Setup endpoint config success\n", "ipa3_odl_pipe_open", 392);
              v6 = ipa3_ctx;
            }
            v8 = *(_QWORD *)(v6 + 34160);
            if ( v8 )
              ipc_log_string(v8, "ipa %s:%d Setup endpoint config success\n", "ipa3_odl_pipe_open", 392);
          }
          v9 = ipa3_odl_ctx;
          *(_DWORD *)(ipa3_odl_ctx + 708) = 0;
          *(_DWORD *)(v9 + 712) = 0;
          *(_QWORD *)(v9 + 700) = 0;
          *(_BYTE *)(v9 + 696) = 1;
          printk(&unk_3C117F, "ipa3_odl_pipe_open");
          v10 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v11 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v11 )
            {
              ipc_log_string(v11, "ipa %s:%d Wake up odl ctl\n", "ipa3_odl_pipe_open", 418);
              v10 = ipa3_ctx;
            }
            v12 = *(_QWORD *)(v10 + 34160);
            if ( v12 )
              ipc_log_string(v12, "ipa %s:%d Wake up odl ctl\n", "ipa3_odl_pipe_open", 418);
          }
          _wake_up(&odl_ctl_msg_wq, 1, 1, 0);
          if ( (*(_WORD *)(ipa3_odl_ctx + 692) & 0x100) != 0 )
          {
            result = 0;
            *(_WORD *)(ipa3_odl_ctx + 692) &= ~0x100u;
            goto LABEL_8;
          }
          goto LABEL_7;
        }
        v15 = v5;
        printk(&unk_3B8565, "ipa3_odl_pipe_open");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d  Setup endpoint config failed\n", "ipa3_odl_pipe_open", 386);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d  Setup endpoint config failed\n", "ipa3_odl_pipe_open", 386);
        }
        result = v15;
        *(_WORD *)(ipa3_odl_ctx + 692) &= ~4u;
      }
    }
    else
    {
      printk(&unk_3B853F, "ipa3_odl_pipe_open");
      v3 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_7;
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d adpl pipe not configured\n", "ipa3_odl_pipe_open", 371);
        v3 = ipa3_ctx;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d adpl pipe not configured\n", "ipa3_odl_pipe_open", 371);
        goto LABEL_7;
      }
    }
  }
  else
  {
    if ( !ipa3_ctx )
    {
LABEL_7:
      result = 0;
      goto LABEL_8;
    }
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d ODL not supported\n", "ipa3_odl_pipe_open", 366);
      v0 = ipa3_ctx;
    }
    result = *(_QWORD *)(v0 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d ODL not supported\n", "ipa3_odl_pipe_open", 366);
      goto LABEL_7;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
