__int64 __fastcall ipa3_cfg_ep_metadata_mask(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
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

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
      goto LABEL_16;
    }
LABEL_46:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_46;
  v4 = a1;
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d pipe=%d, metadata_mask=0x%x\n", "ipa3_cfg_ep_metadata_mask", 9157, a1, *a2);
        v3 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v3 + 34160);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d pipe=%d, metadata_mask=0x%x\n", "ipa3_cfg_ep_metadata_mask", 9157, a1, *a2);
        v3 = ipa3_ctx;
      }
    }
    *(_DWORD *)(v3 + 480LL * a1 + 472) = *a2;
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v12 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v12 + 34160);
        if ( v14 )
          ipc_log_string(v14, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
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
      }
    }
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(59, a1, a2);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
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
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_13;
  }
LABEL_16:
  printk(&unk_3E4584, "ipa3_cfg_ep_metadata_mask");
  v9 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_21;
  v10 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v10 )
  {
    ipc_log_string(
      v10,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_metadata_mask",
      9151,
      a1,
      *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
    v9 = ipa3_ctx;
  }
  v11 = *(_QWORD *)(v9 + 34160);
  if ( v11 )
  {
    ipc_log_string(
      v11,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_metadata_mask",
      9151,
      a1,
      *(_DWORD *)(v9 + 480LL * v4 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_21:
    result = 4294967274LL;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
