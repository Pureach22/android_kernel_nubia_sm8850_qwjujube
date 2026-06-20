__int64 __fastcall ipa_uc_offload_disconn_pipes(unsigned int a1)
{
  __int64 v1; // x21
  __int64 v2; // x0
  unsigned int v3; // w0
  __int64 v4; // x0
  unsigned int v5; // w19
  signed int ep_mapping; // w20
  signed int v7; // w0
  unsigned int v8; // w0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w19
  __int64 v26; // x0
  __int64 v27; // x0

  if ( a1 - 4 <= 0xFFFFFFFC )
  {
    printk(&unk_3EDA3A, "ipa_uc_offload_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_uc_offload %s:%d Invalid client handle %d\n",
        "ipa_uc_offload_disconn_pipes",
        561,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d Invalid client handle %d\n",
        "ipa_uc_offload_disconn_pipes",
        561,
        a1);
    }
    return 4294967274LL;
  }
  v1 = ipa_uc_offload_ctx[a1];
  if ( !v1 )
  {
    printk(&unk_3F0A9E, "ipa_uc_offload_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_uc_offload %s:%d Invalid client Handle\n", "ipa_uc_offload_disconn_pipes", 567);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_uc_offload %s:%d Invalid client Handle\n", "ipa_uc_offload_disconn_pipes", 567);
    }
    return 4294967274LL;
  }
  if ( *(_DWORD *)(v1 + 4) != 2 )
  {
    printk(&unk_3D4256, "ipa_uc_offload_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_uc_offload %s:%d Invalid state\n", "ipa_uc_offload_disconn_pipes", 572);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_uc_offload %s:%d Invalid state\n", "ipa_uc_offload_disconn_pipes", 572);
    }
    return 4294967274LL;
  }
  if ( (*(_DWORD *)v1 & 0xFFFFFFFE) != 2 )
  {
    printk(&unk_3B9A09, "ipa_uc_offload_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_disconn_pipes", 583, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_disconn_pipes", 583, a1);
    }
    return 4294967274LL;
  }
  if ( *(unsigned __int8 *)(v1 + 212) != *(unsigned __int8 *)(v1 + 116) )
  {
    printk(&unk_3A5323, "ipa_uc_ntn_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v20,
        "ipa_uc_offload %s:%d ul and dl smmu enablement do not match\n",
        "ipa_uc_ntn_disconn_pipes",
        520);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v21,
        "ipa_uc_offload %s:%d ul and dl smmu enablement do not match\n",
        "ipa_uc_ntn_disconn_pipes",
        520);
    }
    return 4294967274LL;
  }
  v2 = *(unsigned int *)(v1 + 104);
  *(_DWORD *)(v1 + 4) = 1;
  v3 = ((__int64 (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v2);
  if ( v3 )
  {
    v22 = v3;
    printk(&unk_3EAE21, "ipa_uc_ntn_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(v23, "ipa_uc_offload %s:%d fail to deactivate res: %d\n", "ipa_uc_ntn_disconn_pipes", 528, v22);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v24, "ipa_uc_offload %s:%d fail to deactivate res: %d\n", "ipa_uc_ntn_disconn_pipes", 528, v22);
    }
    return 4294967282LL;
  }
  if ( *(_DWORD *)v1 == 3 )
    v4 = 116;
  else
    v4 = 48;
  if ( *(_DWORD *)v1 == 3 )
    v5 = 117;
  else
    v5 = 49;
  ep_mapping = ipa_get_ep_mapping(v4);
  v7 = ipa_get_ep_mapping(v5);
  v8 = ipa3_tear_down_uc_offload_pipes(ep_mapping, v7, v1 + 112);
  if ( v8 )
  {
    v25 = v8;
    printk(&unk_3B377B, "ipa_uc_ntn_disconn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v26,
        "ipa_uc_offload %s:%d fail to tear down ntn offload pipes, %d\n",
        "ipa_uc_ntn_disconn_pipes",
        543,
        v25);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v27,
        "ipa_uc_offload %s:%d fail to tear down ntn offload pipes, %d\n",
        "ipa_uc_ntn_disconn_pipes",
        543,
        v25);
    }
    return 4294967282LL;
  }
  if ( *(_BYTE *)(v1 + 212) == 1 )
  {
    kfree(*(_QWORD *)(v1 + 272));
    *(_QWORD *)(v1 + 272) = 0;
    ipa_smmu_free_sgt((_QWORD **)(v1 + 264));
    ipa_smmu_free_sgt((_QWORD **)(v1 + 232));
    kfree(*(_QWORD *)(v1 + 176));
    *(_QWORD *)(v1 + 176) = 0;
    ipa_smmu_free_sgt((_QWORD **)(v1 + 168));
    ipa_smmu_free_sgt((_QWORD **)(v1 + 136));
  }
  return 0;
}
