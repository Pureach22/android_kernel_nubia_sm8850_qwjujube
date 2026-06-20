__int64 __fastcall ipa3_cfg_ep_ulso(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x23
  unsigned int v9; // w9
  unsigned int *v10; // x23
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
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
      goto LABEL_17;
    }
LABEL_47:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_47;
  v4 = a1;
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d pipe=%d ipid_min_max_idx=%d is_ulso_pipe=%d\n",
          "ipa3_cfg_ep_ulso",
          9296,
          a1,
          *a2,
          *((unsigned __int8 *)a2 + 4));
        v3 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v3 + 34160);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d pipe=%d ipid_min_max_idx=%d is_ulso_pipe=%d\n",
          "ipa3_cfg_ep_ulso",
          9296,
          a1,
          *a2,
          *((unsigned __int8 *)a2 + 4));
        v3 = ipa3_ctx;
      }
    }
    v8 = v3 + 480LL * a1;
    *(_QWORD *)(v8 + 488) = *(_QWORD *)a2;
    v9 = *(_DWORD *)(ipa3_ctx + 34308);
    if ( v9 <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(v17, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      v9 = *(_DWORD *)(ipa3_ctx + 34308);
    }
    v10 = (unsigned int *)(v8 + 488);
    if ( v9 <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v18 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v18 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v18 + 34160);
        if ( v20 )
          ipc_log_string(v20, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(151, 0, a1, *v10);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v24 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v25 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v25 )
          {
            ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v24 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v24 + 34160);
          if ( v26 )
            ipc_log_string(v26, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_14;
  }
LABEL_17:
  printk(&unk_3E4584, "ipa3_cfg_ep_ulso");
  v12 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_22;
  v13 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v13 )
  {
    ipc_log_string(
      v13,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_ulso",
      9291,
      a1,
      *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
    v12 = ipa3_ctx;
  }
  v14 = *(_QWORD *)(v12 + 34160);
  if ( v14 )
  {
    ipc_log_string(
      v14,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_ulso",
      9291,
      a1,
      *(_DWORD *)(v12 + 480LL * v4 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_22:
    result = 4294967274LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
