__int64 __fastcall ipa_mhi_disconnect_pipe(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  int v5; // w0
  int v6; // w19
  __int64 v7; // x8
  unsigned int v8; // w8
  __int64 v9; // x8
  unsigned int v10; // w8
  char v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w21
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_disconnect_pipe", 1425);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_disconnect_pipe", 1425);
  }
  if ( !ipa_mhi_client_ctx )
  {
    printk(&unk_3E7D1E, "ipa_mhi_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_mhi_client %s:%d IPA MHI was not initialized\n", "ipa_mhi_disconnect_pipe", 1428);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_mhi_client %s:%d IPA MHI was not initialized\n", "ipa_mhi_disconnect_pipe", 1428);
    }
    goto LABEL_69;
  }
  v5 = ((__int64 (__fastcall *)(_QWORD, long double))ipa3_get_client_mapping)(a1, v3);
  v6 = v5;
  if ( ((unsigned int)(v5 - 81) > 0x20 || ((1LL << ((unsigned __int8)v5 - 81)) & 0x1E4100001LL) == 0)
    && (unsigned int)(v5 - 42) >= 2 )
  {
    printk(&unk_3DF96D, "ipa_mhi_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v28 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v28,
        "ipa_mhi_client %s:%d invalid IPA MHI client, client: %d\n",
        "ipa_mhi_disconnect_pipe",
        1435,
        v6);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v29,
        "ipa_mhi_client %s:%d invalid IPA MHI client, client: %d\n",
        "ipa_mhi_disconnect_pipe",
        1435,
        v6);
      result = 4294967274LL;
      goto LABEL_70;
    }
    goto LABEL_69;
  }
  v7 = ipa_mhi_client_ctx;
  if ( *(_BYTE *)(ipa_mhi_client_ctx + 40) == 1 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(ipa_mhi_client_ctx + 44)) == a1 )
    {
      v8 = 0;
LABEL_16:
      v9 = ipa_mhi_client_ctx + 200LL * v8 + 40;
      goto LABEL_34;
    }
    v7 = ipa_mhi_client_ctx;
  }
  if ( *(_BYTE *)(v7 + 240) == 1 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(v7 + 244)) == a1 )
    {
      v8 = 1;
      goto LABEL_16;
    }
    v7 = ipa_mhi_client_ctx;
  }
  if ( *(_BYTE *)(v7 + 440) != 1 )
  {
LABEL_22:
    if ( *(_BYTE *)(v7 + 640) == 1 )
    {
      if ( (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(v7 + 644)) == a1 )
      {
        v10 = 1;
        goto LABEL_33;
      }
      v7 = ipa_mhi_client_ctx;
    }
    if ( *(_BYTE *)(v7 + 840) == 1 )
    {
      if ( (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(v7 + 844)) == a1 )
      {
        v10 = 2;
        goto LABEL_33;
      }
      v7 = ipa_mhi_client_ctx;
    }
    if ( *(_BYTE *)(v7 + 1040) != 1 || (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(v7 + 1044)) != a1 )
    {
      ipa_mhi_disconnect_pipe_channel = 0;
      goto LABEL_65;
    }
    v10 = 3;
    goto LABEL_33;
  }
  if ( (unsigned int)ipa_get_ep_mapping(*(unsigned int *)(v7 + 444)) != a1 )
  {
    v7 = ipa_mhi_client_ctx;
    goto LABEL_22;
  }
  v10 = 0;
LABEL_33:
  v9 = ipa_mhi_client_ctx + 200LL * v10 + 440;
LABEL_34:
  ipa_mhi_disconnect_pipe_channel = v9;
  if ( !v9 )
  {
LABEL_65:
    printk(&unk_3A82BA, "ipa_mhi_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(v26, "ipa_mhi_client %s:%d invalid clnt index\n", "ipa_mhi_disconnect_pipe", 1441);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v27, "ipa_mhi_client %s:%d invalid clnt index\n", "ipa_mhi_disconnect_pipe", 1441);
    }
LABEL_69:
    result = 4294967274LL;
    goto LABEL_70;
  }
  if ( v6 == 110 )
  {
    v11 = 2;
  }
  else
  {
    if ( v6 != 111 )
      goto LABEL_40;
    v11 = 4;
  }
  ipa3_update_mhi_ctrl_state(v11, 0);
LABEL_40:
  ipa3_inc_client_enable_clks();
  v12 = ipa_mhi_reset_channel(ipa_mhi_disconnect_pipe_channel, 0);
  if ( v12 )
  {
    v21 = v12;
    printk(&unk_3A5195, "ipa_mhi_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v22,
        "ipa_mhi_client %s:%d ipa_mhi_reset_channel failed %d\n",
        "ipa_mhi_disconnect_pipe",
        1453,
        v21);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v23,
        "ipa_mhi_client %s:%d ipa_mhi_reset_channel failed %d\n",
        "ipa_mhi_disconnect_pipe",
        1453,
        v21);
    }
    goto LABEL_63;
  }
  mutex_lock(&mhi_client_general_mutex);
  v13 = ((__int64 (__fastcall *)(_QWORD))ipa3_disconnect_mhi_pipe)(a1);
  if ( v13 )
  {
    v21 = v13;
    printk(&unk_3BC836, "ipa_mhi_disconnect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v24,
        "ipa_mhi_client %s:%d IPA core driver failed to disconnect the pipe hdl %d, res %d",
        "ipa_mhi_disconnect_pipe",
        1462,
        a1,
        v21);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v25,
        "ipa_mhi_client %s:%d IPA core driver failed to disconnect the pipe hdl %d, res %d",
        "ipa_mhi_disconnect_pipe",
        1462,
        a1,
        v21);
    }
    mutex_unlock(&mhi_client_general_mutex);
LABEL_63:
    ipa3_dec_client_disable_clks();
    result = v21;
    goto LABEL_70;
  }
  mutex_unlock(&mhi_client_general_mutex);
  ipa3_dec_client_disable_clks();
  if ( ipa3_get_ipc_logbuf() )
  {
    v14 = ipa3_get_ipc_logbuf();
    ipc_log_string(v14, "ipa_mhi_client %s:%d client (ep: %d) disconnected\n", "ipa_mhi_disconnect_pipe", 1469, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v15 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v15, "ipa_mhi_client %s:%d client (ep: %d) disconnected\n", "ipa_mhi_disconnect_pipe", 1469, a1);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v16 = ipa3_get_ipc_logbuf();
    ipc_log_string(v16, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_disconnect_pipe", 1470);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v18 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v18, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_disconnect_pipe", 1470);
    result = 0;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
