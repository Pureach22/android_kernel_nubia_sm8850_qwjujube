__int64 __fastcall ipa3_cfg_ep_conn_track(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x10
  int v7; // w4
  __int64 v8; // x10
  int v9; // t1
  unsigned int v10; // w10
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
LABEL_18:
      printk(&unk_3E4584, "ipa3_cfg_ep_conn_track");
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(
            v15,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_conn_track",
            8913,
            a1,
            *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_conn_track",
            8913,
            a1,
            *(_DWORD *)(v14 + 480LL * v4 + 168));
          result = 4294967274LL;
          goto LABEL_15;
        }
      }
LABEL_28:
      result = 4294967274LL;
      goto LABEL_15;
    }
LABEL_53:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_53;
  v4 = a1;
  v6 = ipa3_ctx + 480LL * a1;
  v9 = *(_DWORD *)(v6 + 168);
  v8 = v6 + 168;
  v7 = v9;
  if ( !a2 || !v7 )
    goto LABEL_18;
  v10 = *(_DWORD *)(v8 + 4);
  if ( v10 <= 0x85 && (v10 & 1) != 0 )
  {
    printk(&unk_3C7C5D, "ipa3_cfg_ep_conn_track");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d IPv6CT does not apply to IPA out EP %d\n", "ipa3_cfg_ep_conn_track", 8918, a1);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d IPv6CT does not apply to IPA out EP %d\n", "ipa3_cfg_ep_conn_track", 8918, a1);
        result = 4294967274LL;
        goto LABEL_15;
      }
    }
    goto LABEL_28;
  }
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d pipe=%d, conn_track_en=%d(%s)\n", "ipa3_cfg_ep_conn_track", 8925, a1);
      v3 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v3 + 34160);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d pipe=%d, conn_track_en=%d(%s)\n", "ipa3_cfg_ep_conn_track", 8925, a1);
      v3 = ipa3_ctx;
    }
  }
  *(_DWORD *)(v3 + 480LL * a1 + 320) = *a2;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v24 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v24 )
        {
          ipc_log_string(v24, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v23 = ipa3_ctx;
        }
        v25 = *(_QWORD *)(v23 + 34160);
        if ( v25 )
          ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_inc_client_enable_clks();
  ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(48, a1, a2);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v29 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v30 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v30 )
        {
          ipc_log_string(v30, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v29 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v29 + 34160);
        if ( v31 )
          ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
    }
  }
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
