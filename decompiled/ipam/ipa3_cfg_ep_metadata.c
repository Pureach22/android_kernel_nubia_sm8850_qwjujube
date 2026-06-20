__int64 __fastcall ipa3_cfg_ep_metadata(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x9
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
  int v29; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
      goto LABEL_23;
    }
LABEL_53:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_53;
  v4 = a1;
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d pipe=%d, mux id=%d\n", "ipa3_cfg_ep_metadata", 10042, a1, *a2);
        v3 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v3 + 34160);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d pipe=%d, mux id=%d\n", "ipa3_cfg_ep_metadata", 10042, a1, *a2);
        v3 = ipa3_ctx;
      }
    }
    *(_DWORD *)(v3 + 480LL * a1 + 476) = *a2;
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
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
      }
    }
    ipa3_inc_client_enable_clks();
    v8 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 51240) == 1 )
    {
      v9 = 480LL * a1;
      *(_DWORD *)(ipa3_ctx + v9 + 328) = 0;
      *(_DWORD *)(ipa3_ctx + v9 + 332) = 0;
      *(_DWORD *)(ipa3_ctx + v9 + 356) = 1;
      ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(41, a1, ipa3_ctx + v9 + 324);
      v8 = ipa3_ctx;
    }
    if ( *(_DWORD *)(v8 + 32240) == 15 )
      v10 = ((unsigned __int8)*a2 << 16) | 0x40000000;
    else
      v10 = (unsigned __int8)*a2 << 16;
    v29 = v10;
    ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(60, a1, &v29);
    v11 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
    {
      v12 = 480LL * a1;
      *(_DWORD *)(ipa3_ctx + v12 + 356) = 1;
      ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(41, a1, ipa3_ctx + v12 + 324);
      v11 = ipa3_ctx;
    }
    if ( *(_DWORD *)(v11 + 34308) <= a1 )
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
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_20;
  }
LABEL_23:
  printk(&unk_3E4584, "ipa3_cfg_ep_metadata");
  v14 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_28;
  v15 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v15 )
  {
    ipc_log_string(
      v15,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_metadata",
      10038,
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
      "ipa3_cfg_ep_metadata",
      10038,
      a1,
      *(_DWORD *)(v14 + 480LL * v4 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_28:
    result = 4294967274LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
