__int64 __fastcall ipa_cfg_ep_ctrl(unsigned int a1, unsigned __int8 *a2)
{
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x22
  unsigned int v8; // w9
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w8
  _BOOL8 v12; // x4
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 result; // x0
  unsigned int v17; // w8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( !a2 || (v3 = ipa3_ctx, *(_DWORD *)(ipa3_ctx + 34308) <= a1) )
  {
    printk(&unk_3B05B7, "ipa_cfg_ep_ctrl");
    v19 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_51;
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d bad parm, clnt_hdl = %d\n", "ipa_cfg_ep_ctrl", 9327, a1);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d bad parm, clnt_hdl = %d\n", "ipa_cfg_ep_ctrl", 9327, a1);
      result = 4294967274LL;
    }
    else
    {
LABEL_51:
      result = 4294967274LL;
    }
    goto LABEL_35;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu && *a2 == 1 )
  {
    printk(&unk_3F5DC3, "ipa_cfg_ep_ctrl");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d pipe suspend is not supported\n", "ipa_cfg_ep_ctrl", 9332);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(v26, "ipa %s:%d pipe suspend is not supported\n", "ipa_cfg_ep_ctrl", 9332);
    }
    __break(0x800u);
    result = 0xFFFFFFFFLL;
    goto LABEL_35;
  }
  if ( *(_BYTE *)(ipa3_ctx + 32268) == 1 )
  {
    printk(&unk_3FBFE2, "ipa_cfg_ep_ctrl");
    v22 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_34;
    v23 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d pipe setting delay is not supported\n", "ipa_cfg_ep_ctrl", 9338);
      v22 = ipa3_ctx;
    }
    result = *(_QWORD *)(v22 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d pipe setting delay is not supported\n", "ipa_cfg_ep_ctrl", 9338);
      goto LABEL_34;
    }
    goto LABEL_35;
  }
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d pipe=%d ep_suspend=%d, ep_delay=%d\n", "ipa_cfg_ep_ctrl", 9345, a1, *a2, a2[1]);
      v3 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v3 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d pipe=%d ep_suspend=%d, ep_delay=%d\n", "ipa_cfg_ep_ctrl", 9345, a1, *a2, a2[1]);
      v3 = ipa3_ctx;
    }
  }
  if ( a1 >= 0x25 )
    goto LABEL_58;
  if ( *(_BYTE *)(v3 + 50153) != 1 || (v7 = v3 + 480LL * a1, v8 = *(_DWORD *)(v7 + 172), v8 > 0x85) || (v8 & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, _QWORD, unsigned __int8 *))ipahal_write_reg_n_fields)(49, a1, a2);
    if ( *a2 != 1 )
      goto LABEL_34;
    if ( a1 != 36 )
    {
      result = 0;
      v17 = *(_DWORD *)(ipa3_ctx + 480LL * a1 + 172);
      if ( v17 <= 0x85 && (v17 & 1) != 0 )
      {
        ipa3_suspend_active_aggr_wa(a1);
        goto LABEL_34;
      }
      goto LABEL_35;
    }
LABEL_58:
    __break(0x5512u);
  }
  if ( v3 )
  {
    v9 = *(_QWORD *)(v3 + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Configuring flow control for pipe = %d\n", "ipa_cfg_ep_ctrl", 9351, a1);
      v3 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v3 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d Configuring flow control for pipe = %d\n", "ipa_cfg_ep_ctrl", 9351, a1);
  }
  v11 = *(_DWORD *)(v7 + 172);
  v12 = 1;
  if ( v11 != 18 && v11 != 42 )
    v12 = v11 == 110;
  v13 = gsi_flow_control_ee(*(unsigned int *)(v7 + 176), a1, 0, a2[1], v12, &v27);
  v14 = ipa3_ctx;
  if ( v13 )
  {
    if ( !ipa3_ctx )
    {
LABEL_34:
      result = 0;
      goto LABEL_35;
    }
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d failed to flow control gsi ch %lu code %d\n",
        "ipa_cfg_ep_ctrl",
        9371,
        *(_QWORD *)(v7 + 176),
        v27);
      v14 = ipa3_ctx;
    }
    result = *(_QWORD *)(v14 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d failed to flow control gsi ch %lu code %d\n",
        "ipa_cfg_ep_ctrl",
        9371,
        *(_QWORD *)(v7 + 176),
        v27);
      goto LABEL_34;
    }
  }
  else
  {
    if ( !ipa3_ctx )
      goto LABEL_34;
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(
        v18,
        "ipa %s:%d flow control sussess gsi ch %lu with code %d\n",
        "ipa_cfg_ep_ctrl",
        9368,
        *(_QWORD *)(v7 + 176),
        v27);
      v14 = ipa3_ctx;
    }
    result = *(_QWORD *)(v14 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d flow control sussess gsi ch %lu with code %d\n",
        "ipa_cfg_ep_ctrl",
        9368,
        *(_QWORD *)(v7 + 176),
        v27);
      goto LABEL_34;
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
