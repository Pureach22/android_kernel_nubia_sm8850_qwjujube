__int64 __fastcall ipa3_cfg_ep_cfg(unsigned int a1, __int64 *a2)
{
  unsigned int v3; // w21
  __int64 v4; // x8
  int v5; // w4
  __int64 v6; // x8
  int v7; // t1
  __int64 v8; // x10
  __int64 v9; // x22
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  __int64 v22; // x8
  unsigned int v23; // w0
  __int64 result; // x0
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
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v3 = a1;
      goto LABEL_20;
    }
LABEL_50:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_50;
  v3 = a1;
  v4 = ipa3_ctx + 480LL * a1;
  v7 = *(_DWORD *)(v4 + 168);
  v6 = v4 + 168;
  v5 = v7;
  if ( a2 && v5 )
  {
    v8 = *a2;
    *(_DWORD *)(v6 + 300) = *((_DWORD *)a2 + 2);
    *(_QWORD *)(v6 + 292) = v8;
    ((void (__fastcall *)(_QWORD))ipa3_cfg_ep_cfg_pipe_replicate)(a1);
    v9 = 480LL * a1;
    *(_BYTE *)(ipa3_ctx + v9 + 469) = ((__int64 (__fastcall *)(_QWORD))ipa3_get_qmb_master_sel)(*(unsigned int *)(ipa3_ctx + v9 + 172));
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        v12 = ipa3_ctx + 480LL * a1;
        ipc_log_string(
          v11,
          "ipa %s:%d pipe=%d, frag_ofld_en=%d cs_ofld_en=%d mdata_hdr_ofst=%d gen_qmb_master_sel=%d pipe_replicate_en=%d\n",
          "ipa3_cfg_ep_cfg",
          9061,
          a1,
          *(unsigned __int8 *)(v12 + 460),
          *(_DWORD *)(v12 + 464),
          *(unsigned __int8 *)(v12 + 468),
          *(unsigned __int8 *)(v12 + 469),
          *(unsigned __int8 *)(v12 + 471));
        v10 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v10 + 34160);
      if ( v13 )
      {
        v14 = v10 + 480LL * a1;
        ipc_log_string(
          v13,
          "ipa %s:%d pipe=%d, frag_ofld_en=%d cs_ofld_en=%d mdata_hdr_ofst=%d gen_qmb_master_sel=%d pipe_replicate_en=%d\n",
          "ipa3_cfg_ep_cfg",
          9061,
          a1,
          *(unsigned __int8 *)(v14 + 460),
          *(_DWORD *)(v14 + 464),
          *(unsigned __int8 *)(v14 + 468),
          *(unsigned __int8 *)(v14 + 469),
          *(unsigned __int8 *)(v14 + 471));
        v10 = ipa3_ctx;
      }
    }
    if ( *(_DWORD *)(v10 + 34308) <= a1 )
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
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
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
      }
    }
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(57, a1, ipa3_ctx + 480LL * a1 + 460);
    v22 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
    {
      v23 = *(_DWORD *)(ipa3_ctx + 480LL * a1 + 172);
      if ( v23 <= 0x85 && (v23 & 1) != 0 )
      {
        *(_BYTE *)(ipa3_ctx + v9 + 470) = ipa3_get_tx_instance(v23, v15, v16, v17, v18, v19, v20, v21);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
          61,
          0,
          a1,
          *(unsigned __int8 *)(ipa3_ctx + v9 + 470));
        v22 = ipa3_ctx;
      }
    }
    if ( *(_DWORD *)(v22 + 34308) <= a1 )
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
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v37 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v38 )
          {
            ipc_log_string(v38, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v37 = ipa3_ctx;
          }
          v39 = *(_QWORD *)(v37 + 34160);
          if ( v39 )
            ipc_log_string(v39, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_17;
  }
LABEL_20:
  printk(&unk_3E4584, "ipa3_cfg_ep_cfg");
  v25 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_25;
  v26 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v26 )
  {
    ipc_log_string(
      v26,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_cfg",
      9041,
      a1,
      *(_DWORD *)(ipa3_ctx + 480LL * v3 + 168));
    v25 = ipa3_ctx;
  }
  v27 = *(_QWORD *)(v25 + 34160);
  if ( v27 )
  {
    ipc_log_string(
      v27,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_cfg",
      9041,
      a1,
      *(_DWORD *)(v25 + 480LL * v3 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_25:
    result = 4294967274LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
