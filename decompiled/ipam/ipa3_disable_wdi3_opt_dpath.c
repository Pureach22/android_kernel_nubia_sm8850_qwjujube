__int64 __fastcall ipa3_disable_wdi3_opt_dpath(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w20
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  long double v8; // q0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x8
  int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0

  v3 = a1;
  _ReadStatusReg(SP_EL0);
  if ( (int)ipa_get_wdi_version(a1) > 1 )
  {
    ipa3_inc_client_enable_clks();
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        v8 = ipc_log_string(v10, "ipa %s:%d ep_rx = %d, ep_tx = %d\n", "ipa3_disable_wdi3_opt_dpath", 1550, v3, a2);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        v8 = ipc_log_string(v11, "ipa %s:%d ep_rx = %d, ep_tx = %d\n", "ipa3_disable_wdi3_opt_dpath", 1550, v3, a2);
    }
    if ( (((__int64 (__fastcall *)(_QWORD, long double))ipa_wdi_opt_dpath_ctrl_enabled)(0, v8) & 1) == 0 )
      ((void (__fastcall *)(_QWORD))ipa3_delete_dl_opt_wdi_dpath_flt_rules)(v3);
    v12 = ipa3_disable_data_path(a2);
    if ( v12 )
    {
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = v12;
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(
            v15,
            "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
            "ipa3_disable_wdi3_opt_dpath",
            1560,
            v14,
            a2);
          v13 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v13 + 34160);
        if ( v16 )
          ipc_log_string(
            v16,
            "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
            "ipa3_disable_wdi3_opt_dpath",
            1560,
            v14,
            a2);
      }
    }
    else
    {
      if ( !(unsigned int)ipa_stop_gsi_channel(a2) )
      {
        v7 = 0;
        goto LABEL_28;
      }
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d failed to stop gsi tx channel\n", "ipa3_disable_wdi3_opt_dpath", 1568);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d failed to stop gsi tx channel\n", "ipa3_disable_wdi3_opt_dpath", 1568);
      }
    }
    v7 = -14;
LABEL_28:
    ipa3_dec_client_disable_clks();
    goto LABEL_29;
  }
  v4 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_20;
  v5 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v5 )
  {
    ipc_log_string(v5, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_disable_wdi3_opt_dpath", 1544);
    v4 = ipa3_ctx;
  }
  v6 = *(_QWORD *)(v4 + 34160);
  if ( v6 )
  {
    ipc_log_string(v6, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_disable_wdi3_opt_dpath", 1544);
    v7 = -14;
  }
  else
  {
LABEL_20:
    v7 = -14;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v7;
}
