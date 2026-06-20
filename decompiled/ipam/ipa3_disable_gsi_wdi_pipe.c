__int64 __fastcall ipa3_disable_gsi_wdi_pipe(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x24
  unsigned int v6; // w0
  unsigned int v7; // w5
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int ep_mapping; // w0
  unsigned int v12; // w21
  unsigned int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  _WORD v34[2]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v34[0] = 0;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d ep=%d\n", "ipa3_disable_gsi_wdi_pipe", 2451, a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d ep=%d\n", "ipa3_disable_gsi_wdi_pipe", 2451, a1);
  }
  if ( a1 >= 0x25 )
    goto LABEL_62;
  v5 = ipa3_ctx + 480LL * a1;
  if ( *(_DWORD *)(v5 + 620) == 3 )
  {
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    ipa3_inc_client_enable_clks();
    v6 = ipa3_disable_data_path(a1);
    if ( v6 )
    {
      v17 = v6;
      printk(&unk_3EF093, "ipa3_disable_gsi_wdi_pipe");
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v23 )
        {
          ipc_log_string(
            v23,
            "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
            "ipa3_disable_gsi_wdi_pipe",
            2464,
            v17,
            a1);
          v22 = ipa3_ctx;
        }
        v24 = *(_QWORD *)(v22 + 34160);
        if ( v24 )
          ipc_log_string(
            v24,
            "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
            "ipa3_disable_gsi_wdi_pipe",
            2464,
            v17,
            a1);
      }
      goto LABEL_32;
    }
    v7 = *(_DWORD *)(v5 + 172);
    if ( v7 > 0x85 || (v7 & 1) != 0 )
    {
LABEL_23:
      if ( v7 <= 0x85 && (v7 & 1) == 0 )
      {
        v34[0] = 256;
        ipa_cfg_ep_ctrl(a1, v34);
      }
      *(_DWORD *)(v5 + 620) &= ~2u;
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d client (ep: %d) disabled\n", "ipa3_disable_gsi_wdi_pipe", 2507, a1);
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
          ipc_log_string(v16, "ipa %s:%d client (ep: %d) disabled\n", "ipa3_disable_gsi_wdi_pipe", 2507, a1);
      }
LABEL_31:
      v17 = 0;
LABEL_32:
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      ipa3_dec_client_disable_clks();
      goto LABEL_35;
    }
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(
          v9,
          "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n",
          "ipa3_disable_gsi_wdi_pipe",
          2475,
          a1,
          v7);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(
          v10,
          "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n",
          "ipa3_disable_gsi_wdi_pipe",
          2475,
          a1,
          *(_DWORD *)(v5 + 172));
    }
    v34[0] = 0;
    ipa_cfg_ep_ctrl(a1, v34);
    ep_mapping = ipa_get_ep_mapping(11);
    if ( ep_mapping == -1 )
    {
      printk(&unk_3DA941, "ipa3_disable_gsi_wdi_pipe");
      v25 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v26 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d Client %u is not mapped\n", "ipa3_disable_gsi_wdi_pipe", 2483, 11);
          v25 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v25 + 34160);
        if ( v27 )
          ipc_log_string(v27, "ipa %s:%d Client %u is not mapped\n", "ipa3_disable_gsi_wdi_pipe", 2483, 11);
      }
      goto LABEL_31;
    }
    v12 = ep_mapping;
    if ( ep_mapping <= 0x23 )
    {
      if ( *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 168) == 1 )
      {
        v13 = ipa3_disable_data_path(ep_mapping);
        if ( v13 )
        {
          v17 = v13;
          printk(&unk_3D8F66, "ipa3_disable_gsi_wdi_pipe");
          v28 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v29 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v29 )
            {
              ipc_log_string(v29, "ipa %s:%d disable data path failed\n", "ipa3_disable_gsi_wdi_pipe", 2489);
              v28 = ipa3_ctx;
            }
            v30 = *(_QWORD *)(v28 + 34160);
            if ( v30 )
              ipc_log_string(v30, "ipa %s:%d disable data path failed\n", "ipa3_disable_gsi_wdi_pipe", 2489);
          }
          printk(&unk_3A77EF, "ipa3_disable_gsi_wdi_pipe");
          v31 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v32 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v32 )
            {
              ipc_log_string(v32, "ipa %s:%d res=%d clnt=%d\n", "ipa3_disable_gsi_wdi_pipe", 2491, v17, v12);
              v31 = ipa3_ctx;
            }
            v33 = *(_QWORD *)(v31 + 34160);
            if ( v33 )
              ipc_log_string(v33, "ipa %s:%d res=%d clnt=%d\n", "ipa3_disable_gsi_wdi_pipe", 2491, v17, v12);
          }
          goto LABEL_32;
        }
      }
      usleep_range_state(10000, 10000, 2);
      v7 = *(_DWORD *)(v5 + 172);
      goto LABEL_23;
    }
LABEL_62:
    __break(0x5512u);
  }
  printk(&unk_3C4C2C, "ipa3_disable_gsi_wdi_pipe");
  v19 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_46;
  v20 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v20 )
  {
    ipc_log_string(
      v20,
      "ipa %s:%d WDI channel bad state %d\n",
      "ipa3_disable_gsi_wdi_pipe",
      2456,
      *(_DWORD *)(v5 + 620));
    v19 = ipa3_ctx;
  }
  v21 = *(_QWORD *)(v19 + 34160);
  if ( v21 )
  {
    ipc_log_string(
      v21,
      "ipa %s:%d WDI channel bad state %d\n",
      "ipa3_disable_gsi_wdi_pipe",
      2456,
      *(_DWORD *)(v5 + 620));
    v17 = -14;
  }
  else
  {
LABEL_46:
    v17 = -14;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v17;
}
