__int64 __fastcall ipa3_xdci_connect(_QWORD *a1)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w20
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0

  v2 = (unsigned int)a1;
  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d entry\n", "ipa3_xdci_connect", 863);
      v3 = ipa3_ctx;
    }
    a1 = *(_QWORD **)(v3 + 34160);
    if ( a1 )
    {
      a1 = (_QWORD *)ipc_log_string(a1, "ipa %s:%d entry\n", "ipa3_xdci_connect", 863);
      v3 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v3 + 34308) <= v2 )
    goto LABEL_23;
  if ( v2 >= 0x24 )
  {
    __break(0x5512u);
    *a1 = v1;
    JUMPOUT(0x8F7E8);
  }
  if ( *(_DWORD *)(v3 + 480LL * v2 + 168) )
  {
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    ipa3_inc_client_enable_clks();
    v5 = ((__int64 (__fastcall *)(_QWORD))ipa3_start_gsi_channel)(v2);
    if ( v5 )
    {
      v10 = v5;
      printk(&unk_3B48F7, "ipa3_xdci_connect");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d failed to start gsi channel clnt_hdl=%u\n", "ipa3_xdci_connect", 876, v2);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(v17, "ipa %s:%d failed to start gsi channel clnt_hdl=%u\n", "ipa3_xdci_connect", 876, v2);
      }
    }
    else
    {
      v6 = ipa3_enable_data_path(v2);
      if ( v6 )
      {
        v10 = v6;
        printk(&unk_3BAC19, "ipa3_xdci_connect");
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v19 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v19 )
          {
            ipc_log_string(
              v19,
              "ipa %s:%d enable data path failed res=%d clnt_hdl=%d.\n",
              "ipa3_xdci_connect",
              883,
              v10,
              v2);
            v18 = ipa3_ctx;
          }
          v20 = *(_QWORD *)(v18 + 34160);
          if ( v20 )
            ipc_log_string(
              v20,
              "ipa %s:%d enable data path failed res=%d clnt_hdl=%d.\n",
              "ipa3_xdci_connect",
              883,
              v10,
              v2);
        }
        ipa_stop_gsi_channel(v2);
      }
      else
      {
        v7 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v8 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v8 )
          {
            ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_xdci_connect", 887);
            v7 = ipa3_ctx;
          }
          v9 = *(_QWORD *)(v7 + 34160);
          if ( v9 )
            ipc_log_string(v9, "ipa %s:%d exit\n", "ipa3_xdci_connect", 887);
        }
        v10 = 0;
      }
    }
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    ipa3_dec_client_disable_clks();
    result = v10;
  }
  else
  {
LABEL_23:
    printk(&unk_3F1C01, "ipa3_xdci_connect");
    v12 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_28;
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_connect", 867);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_connect", 867);
      result = 4294967274LL;
    }
    else
    {
LABEL_28:
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
