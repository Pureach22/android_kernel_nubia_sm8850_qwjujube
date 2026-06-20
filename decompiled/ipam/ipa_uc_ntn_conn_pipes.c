__int64 __fastcall ipa_uc_ntn_conn_pipes(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w22
  unsigned int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned __int8 v10; // w3
  int v11; // w0
  unsigned int v12; // w0
  __int64 result; // x0
  unsigned int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v23; // w19
  __int64 v24; // x0
  __int64 v25; // x0
  int v26; // w20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0

  if ( *(unsigned __int8 *)(a3 + 212) != *(unsigned __int8 *)(a3 + 116) )
  {
    printk(&unk_3A5323, "ipa_uc_ntn_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_uc_offload %s:%d ul and dl smmu enablement do not match\n",
        "ipa_uc_ntn_conn_pipes",
        415);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d ul and dl smmu enablement do not match\n",
        "ipa_uc_ntn_conn_pipes",
        415);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + 104) & 7) != 0 || (*(_BYTE *)(a1 + 136) & 7) != 0 )
  {
    printk(&unk_3B991F, "ipa_uc_ntn_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v17 = ipa3_get_ipc_logbuf();
      ipc_log_string(v17, "ipa_uc_offload %s:%d alignment failure on TX\n", "ipa_uc_ntn_conn_pipes", 422);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v18, "ipa_uc_offload %s:%d alignment failure on TX\n", "ipa_uc_ntn_conn_pipes", 422);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + 8) & 7) != 0 || (*(_BYTE *)(a1 + 40) & 7) != 0 )
  {
    printk(&unk_3B994F, "ipa_uc_ntn_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_uc_offload %s:%d alignment failure on RX\n", "ipa_uc_ntn_conn_pipes", 427);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_uc_offload %s:%d alignment failure on RX\n", "ipa_uc_ntn_conn_pipes", 427);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v4 = *(_DWORD *)(a3 + 4);
  v7 = ipa_pm_activate_sync(*(_DWORD *)(a3 + 104));
  if ( v7 )
  {
    v23 = v7;
    printk(&unk_3B997F, "ipa_uc_ntn_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_uc_offload %s:%d fail to activate: %d\n", "ipa_uc_ntn_conn_pipes", 433, v23);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_uc_offload %s:%d fail to activate: %d\n", "ipa_uc_ntn_conn_pipes", 433, v23);
    }
    return v23;
  }
  v8 = *(_QWORD *)(a3 + 64);
  v9 = *(_QWORD *)(a3 + 8);
  v10 = *(_BYTE *)(a3 + 16);
  *(_DWORD *)(a3 + 4) = 2;
  v11 = ipa3_setup_uc_ntn_pipes((unsigned int *)a1, v8, v9, v10, a2);
  if ( !v11 )
  {
    if ( *(_BYTE *)(a3 + 212) != 1 )
      return 0;
    v12 = ipa_uc_ntn_alloc_conn_smmu_info(a3 + 208, a1 + 96);
    if ( !v12 )
    {
      result = ipa_uc_ntn_alloc_conn_smmu_info(a3 + 112, a1);
      if ( (_DWORD)result )
      {
        v14 = result;
        ipa_uc_ntn_free_conn_smmu_info(a3 + 208);
        printk(&unk_3B99AC, "ipa_uc_ntn_conn_pipes");
        if ( ipa3_get_ipc_logbuf() )
        {
          v15 = ipa3_get_ipc_logbuf();
          ipc_log_string(v15, "ipa_uc_offload %s:%d alloc failure on RX\n", "ipa_uc_ntn_conn_pipes", 459);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v16 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v16, "ipa_uc_offload %s:%d alloc failure on RX\n", "ipa_uc_ntn_conn_pipes", 459);
        }
        return v14;
      }
      return result;
    }
    v23 = v12;
    printk(&unk_3C5A29, "ipa_uc_ntn_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(v29, "ipa_uc_offload %s:%d alloc failure on TX\n", "ipa_uc_ntn_conn_pipes", 452);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v30 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v30, "ipa_uc_offload %s:%d alloc failure on TX\n", "ipa_uc_ntn_conn_pipes", 452);
    }
    return v23;
  }
  v26 = v11;
  printk(&unk_3F0A63, "ipa_uc_ntn_conn_pipes");
  if ( ipa3_get_ipc_logbuf() )
  {
    v27 = ipa3_get_ipc_logbuf();
    ipc_log_string(v27, "ipa_uc_offload %s:%d fail to setup uc offload pipes: %d\n", "ipa_uc_ntn_conn_pipes", 442, v26);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v28 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v28, "ipa_uc_offload %s:%d fail to setup uc offload pipes: %d\n", "ipa_uc_ntn_conn_pipes", 442, v26);
  }
  *(_DWORD *)(a3 + 4) = v4;
  return 4294967282LL;
}
