__int64 __fastcall ipa_disable_wdi_pipe(_QWORD *ep_mapping)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned int v8; // w0
  unsigned int v9; // w5
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w20
  unsigned int v14; // w0
  unsigned int v15; // w20
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  unsigned int v33; // w21
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  _WORD v40[2]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+28h] [xbp-8h]

  v2 = (unsigned int)ep_mapping;
  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40[0] = 0;
  if ( *(_BYTE *)(ipa3_ctx + 51102) == 1 )
  {
    result = ipa_pm_wrapper_disable_pipe((unsigned int)ep_mapping);
LABEL_51:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)ep_mapping )
    goto LABEL_33;
  if ( (unsigned int)ep_mapping >= 0x24 )
    goto LABEL_80;
  if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
  {
LABEL_33:
    printk(&unk_3A77D5, "ipa_disable_wdi_pipe");
    v16 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_50;
    v17 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d bad parm, %d\n", "ipa_disable_wdi_pipe", 2602, v2);
      v16 = ipa3_ctx;
    }
    v18 = *(_QWORD *)(v16 + 34160);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d bad parm, %d\n", "ipa_disable_wdi_pipe", 2602, v2);
      result = 4294967274LL;
    }
    else
    {
LABEL_50:
      result = 4294967274LL;
    }
    goto LABEL_51;
  }
  if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 && (unsigned int)ipa_get_wdi_version() == 1 )
  {
    result = ipa3_disable_gsi_wdi_pipe(v2);
    goto LABEL_51;
  }
  result = ipa3_uc_state_check();
  if ( (_DWORD)result )
    goto LABEL_51;
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d ep=%d\n", "ipa_disable_wdi_pipe", 2613, v2);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d ep=%d\n", "ipa_disable_wdi_pipe", 2613, v2);
      v4 = ipa3_ctx;
    }
  }
  v7 = v4 + 480LL * v2;
  if ( *(_DWORD *)(v7 + 616) != 3 )
  {
    printk(&unk_3C4C2C, "ipa_disable_wdi_pipe");
    v23 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_63;
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d WDI channel bad state %d\n", "ipa_disable_wdi_pipe", 2618, *(_DWORD *)(v7 + 616));
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d WDI channel bad state %d\n", "ipa_disable_wdi_pipe", 2618, *(_DWORD *)(v7 + 616));
      result = 4294967282LL;
    }
    else
    {
LABEL_63:
      result = 4294967282LL;
    }
    goto LABEL_51;
  }
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
  ipa3_inc_client_enable_clks();
  v8 = ipa3_disable_data_path(v2);
  if ( v8 )
  {
    v26 = v8;
    printk(&unk_3EF093, "ipa_disable_wdi_pipe");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
          "ipa_disable_wdi_pipe",
          2626,
          v26,
          v2);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
          "ipa_disable_wdi_pipe",
          2626,
          v26,
          v2);
LABEL_62:
        v15 = -1;
        goto LABEL_47;
      }
    }
LABEL_79:
    v15 = -1;
    goto LABEL_47;
  }
  v9 = *(_DWORD *)(v7 + 172);
  if ( v9 > 0x85 || (v9 & 1) != 0 )
    goto LABEL_31;
  v10 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n", "ipa_disable_wdi_pipe", 2638, v2, v9);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
      ipc_log_string(
        v12,
        "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n",
        "ipa_disable_wdi_pipe",
        2638,
        v2,
        *(_DWORD *)(v7 + 172));
  }
  v40[0] = 0;
  ipa_cfg_ep_ctrl(v2, v40);
  ep_mapping = (_QWORD *)ipa_get_ep_mapping(11);
  if ( (_DWORD)ep_mapping == -1 )
  {
    printk(&unk_3DA941, "ipa_disable_wdi_pipe");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d Client %u is not mapped\n", "ipa_disable_wdi_pipe", 2646, 11);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(v32, "ipa %s:%d Client %u is not mapped\n", "ipa_disable_wdi_pipe", 2646, 11);
    }
    goto LABEL_46;
  }
  v13 = (unsigned int)ep_mapping;
  if ( (unsigned int)ep_mapping <= 0x23 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) != 1
      || (v14 = ipa3_disable_data_path((unsigned int)ep_mapping)) == 0 )
    {
      usleep_range_state(10000, 10000, 2);
LABEL_31:
      if ( (unsigned int)ipa3_uc_send_cmd(v2, 0x64u, 0x60u, 0, 2500) )
      {
        v15 = -14;
LABEL_47:
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        ipa3_dec_client_disable_clks();
        result = v15;
        goto LABEL_51;
      }
      v19 = *(_DWORD *)(v7 + 172);
      if ( v19 <= 0x85 && (v19 & 1) == 0 )
      {
        v40[0] = 256;
        ipa_cfg_ep_ctrl(v2, v40);
      }
      *(_DWORD *)(v7 + 616) &= ~2u;
      v20 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v21 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v21 )
        {
          ipc_log_string(v21, "ipa %s:%d client (ep: %d) disabled\n", "ipa_disable_wdi_pipe", 2682, v2);
          v20 = ipa3_ctx;
        }
        v22 = *(_QWORD *)(v20 + 34160);
        if ( v22 )
          ipc_log_string(v22, "ipa %s:%d client (ep: %d) disabled\n", "ipa_disable_wdi_pipe", 2682, v2);
      }
LABEL_46:
      v15 = 0;
      goto LABEL_47;
    }
    v33 = v14;
    printk(&unk_3D8F66, "ipa_disable_wdi_pipe");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d disable data path failed\n", "ipa_disable_wdi_pipe", 2652);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d disable data path failed\n", "ipa_disable_wdi_pipe", 2652);
    }
    printk(&unk_3A77EF, "ipa_disable_wdi_pipe");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d res=%d clnt=%d\n", "ipa_disable_wdi_pipe", 2654, v33, v13);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
      {
        ipc_log_string(v39, "ipa %s:%d res=%d clnt=%d\n", "ipa_disable_wdi_pipe", 2654, v33, v13);
        goto LABEL_62;
      }
    }
    goto LABEL_79;
  }
LABEL_80:
  __break(0x5512u);
  *ep_mapping = v1;
  return ipa_pm_wrapper_disable_pipe((char *)ep_mapping + 217);
}
