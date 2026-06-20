__int64 __fastcall ipa3_cfg_ep_prod_cfg(
        unsigned int a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w21
  _DWORD *v11; // x9
  unsigned int v12; // w9
  int v13; // w10
  __int64 v14; // x22
  __int64 v15; // x8
  char tx_instance; // w0
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v10 = a1;
      goto LABEL_15;
    }
LABEL_45:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_45;
  v10 = a1;
  v11 = (_DWORD *)(ipa3_ctx + 168 + 480LL * a1);
  if ( !*v11 )
    goto LABEL_15;
  v12 = v11[1];
  if ( v12 > 0x85 )
  {
    if ( a2 )
      goto LABEL_9;
LABEL_15:
    printk(&unk_3E4584, "ipa3_cfg_ep_prod_cfg");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
          "ipa3_cfg_ep_prod_cfg",
          9106,
          a1,
          *(_DWORD *)(ipa3_ctx + 480LL * v10 + 168));
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(
          v20,
          "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
          "ipa3_cfg_ep_prod_cfg",
          9106,
          a1,
          *(_DWORD *)(v18 + 480LL * v10 + 168));
    }
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( !a2 || (v12 & 1) == 0 )
    goto LABEL_15;
LABEL_9:
  v13 = *(_DWORD *)((char *)a2 + 3);
  v14 = 480LL * a1;
  v15 = ipa3_ctx + 168 + v14;
  *(_DWORD *)(v15 + 328) = *a2;
  *(_DWORD *)(v15 + 331) = v13;
  tx_instance = ipa3_get_tx_instance(*(_DWORD *)(ipa3_ctx + v14 + 172), a3, a4, a5, a6, a7, a8, a9);
  *(_BYTE *)(ipa3_ctx + v14 + 470) = tx_instance;
  *(_BYTE *)(ipa3_ctx + v14 + 496) = tx_instance;
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
  ipa3_inc_client_enable_clks();
  ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(61, a1, ipa3_ctx + 480LL * a1 + 496);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v31 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v31 )
        {
          ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v30 = ipa3_ctx;
        }
        v32 = *(_QWORD *)(v30 + 34160);
        if ( v32 )
          ipc_log_string(v32, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
