__int64 __fastcall ipa3_cfg_ep_nat(unsigned int a1, unsigned int *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x10
  int v7; // w4
  __int64 v8; // x10
  int v9; // t1
  unsigned int v10; // w10
  __int64 v11; // x0
  __int64 v12; // x5
  const char *v13; // x6
  __int64 v14; // x0
  __int64 v15; // x5
  const char *v16; // x6
  __int64 v17; // x8
  __int64 result; // x0
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
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
LABEL_26:
      printk(&unk_3E4584, "ipa3_cfg_ep_nat");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v20 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v20 )
        {
          ipc_log_string(
            v20,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_nat",
            8865,
            a1,
            *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
          v19 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v19 + 34160);
        if ( v21 )
        {
          ipc_log_string(
            v21,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_nat",
            8865,
            a1,
            *(_DWORD *)(v19 + 480LL * v4 + 168));
          result = 4294967274LL;
          goto LABEL_23;
        }
      }
LABEL_36:
      result = 4294967274LL;
      goto LABEL_23;
    }
LABEL_61:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_61;
  v4 = a1;
  v6 = ipa3_ctx + 480LL * a1;
  v9 = *(_DWORD *)(v6 + 168);
  v8 = v6 + 168;
  v7 = v9;
  if ( !a2 || !v7 )
    goto LABEL_26;
  v10 = *(_DWORD *)(v8 + 4);
  if ( v10 <= 0x85 && (v10 & 1) != 0 )
  {
    printk(&unk_3F3087, "ipa3_cfg_ep_nat");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d NAT does not apply to IPA out EP %d\n", "ipa3_cfg_ep_nat", 8870, a1);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d NAT does not apply to IPA out EP %d\n", "ipa3_cfg_ep_nat", 8870, a1);
        result = 4294967274LL;
        goto LABEL_23;
      }
    }
    goto LABEL_36;
  }
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      v12 = *a2;
      if ( (unsigned int)v12 > 2 )
        v13 = "undefined";
      else
        v13 = off_1E4138[v12];
      ipc_log_string(
        v11,
        "ipa %s:%d pipe=%d, nat_en=%d(%s), nat_exc_suppress=%d\n",
        "ipa3_cfg_ep_nat",
        8878,
        a1,
        v12,
        v13,
        *((unsigned __int8 *)a2 + 4));
      v3 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v3 + 34160);
    if ( v14 )
    {
      v15 = *a2;
      if ( (unsigned int)v15 > 2 )
        v16 = "undefined";
      else
        v16 = off_1E4138[v15];
      ipc_log_string(
        v14,
        "ipa %s:%d pipe=%d, nat_en=%d(%s), nat_exc_suppress=%d\n",
        "ipa3_cfg_ep_nat",
        8878,
        a1,
        v15,
        v16,
        *((unsigned __int8 *)a2 + 4));
      v3 = ipa3_ctx;
    }
  }
  *(_QWORD *)(v3 + 480LL * a1 + 312) = *(_QWORD *)a2;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v28 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v29 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
          ipc_log_string(v30, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_inc_client_enable_clks();
  ((void (__fastcall *)(__int64, _QWORD, unsigned int *))ipahal_write_reg_n_fields)(47, a1, a2);
  v17 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
  {
    ((void (__fastcall *)(__int64, _QWORD, unsigned int *))ipahal_write_reg_n_fields)(152, a1, a2);
    v17 = ipa3_ctx;
  }
  if ( *(_DWORD *)(v17 + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
        ipc_log_string(v33, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v35 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v35 )
        {
          ipc_log_string(v35, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v34 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v34 + 34160);
        if ( v36 )
          ipc_log_string(v36, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
