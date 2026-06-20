__int64 __fastcall ipa3_set_reset_client_prod_pipe_delay(char a1, unsigned int a2)
{
  unsigned int ep_mapping; // w0
  unsigned int v5; // w20
  __int64 v6; // x23
  __int64 v7; // x23
  int v8; // t1
  unsigned int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w21
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  _BYTE v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v24[1] = a1;
  if ( a2 <= 0x85 && (a2 & 1) != 0 )
  {
    printk(&unk_3CBF4D, "ipa3_set_reset_client_prod_pipe_delay");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d client (%d) not PROD\n", "ipa3_set_reset_client_prod_pipe_delay", 1370, a2);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d client (%d) not PROD\n", "ipa3_set_reset_client_prod_pipe_delay", 1370, a2);
    }
    goto LABEL_26;
  }
  ep_mapping = ipa_get_ep_mapping(a2);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3E08A7, "ipa3_set_reset_client_prod_pipe_delay");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d client (%d) not valid\n", "ipa3_set_reset_client_prod_pipe_delay", 1377, a2);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d client (%d) not valid\n", "ipa3_set_reset_client_prod_pipe_delay", 1377, a2);
    }
LABEL_26:
    v13 = -22;
    goto LABEL_15;
  }
  v5 = ep_mapping;
  if ( ep_mapping < 0x25 )
  {
    v6 = ipa3_ctx + 480LL * ep_mapping;
    client_lock_unlock_cb(a2, 1);
    v8 = *(_DWORD *)(v6 + 168);
    v7 = v6 + 168;
    if ( v8 && *(_BYTE *)(v7 + 404) == 1 )
    {
      *(_BYTE *)(v7 + 468) = a1 & 1;
      v9 = ipa_cfg_ep_ctrl(v5, v24);
      if ( v9 )
      {
        v13 = v9;
        printk(&unk_3B7A7E, "ipa3_set_reset_client_prod_pipe_delay");
        v21 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v22 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v22 )
          {
            ipc_log_string(
              v22,
              "ipa %s:%d client (ep: %d) failed result=%d\n",
              "ipa3_set_reset_client_prod_pipe_delay",
              1390,
              v5,
              v13);
            v21 = ipa3_ctx;
          }
          v23 = *(_QWORD *)(v21 + 34160);
          if ( v23 )
            ipc_log_string(
              v23,
              "ipa %s:%d client (ep: %d) failed result=%d\n",
              "ipa3_set_reset_client_prod_pipe_delay",
              1390,
              v5,
              v13);
        }
        goto LABEL_14;
      }
      v10 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d client (ep: %d) success\n", "ipa3_set_reset_client_prod_pipe_delay", 1392, v5);
          v10 = ipa3_ctx;
        }
        v12 = *(_QWORD *)(v10 + 34160);
        if ( v12 )
          ipc_log_string(v12, "ipa %s:%d client (ep: %d) success\n", "ipa3_set_reset_client_prod_pipe_delay", 1392, v5);
      }
    }
    v13 = 0;
LABEL_14:
    client_lock_unlock_cb(a2, 0);
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return v13;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))client_lock_unlock_cb)();
}
