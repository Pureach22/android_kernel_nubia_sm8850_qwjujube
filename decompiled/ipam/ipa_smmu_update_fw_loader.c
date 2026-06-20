__int64 ipa_smmu_update_fw_loader()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x19
  int v4; // w24
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w0
  unsigned int v22; // w19
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0

  v0 = ipa3_ctx;
  if ( byte_1F79A7 != 1 )
  {
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d smmu is disabled\n", "ipa_smmu_update_fw_loader", 11737);
        v0 = ipa3_ctx;
      }
      result = *(_QWORD *)(v0 + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d smmu is disabled\n", "ipa_smmu_update_fw_loader", 11737);
    }
    return 0;
  }
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d smmu is enabled\n", "ipa_smmu_update_fw_loader", 11699);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d smmu is enabled\n", "ipa_smmu_update_fw_loader", 11699);
  }
  v3 = 0;
  v4 = 0;
  do
  {
    if ( (smmu_info[v3] & 1) != 0 )
    {
      v5 = ipa3_ctx;
      ++v4;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d CB %d probed\n", "ipa_smmu_update_fw_loader", 11705, v3);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(v7, "ipa %s:%d CB %d probed\n");
      }
    }
    else
    {
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d CB %d not probed yet\n", "ipa_smmu_update_fw_loader", 11702, v3);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d CB %d not probed yet\n");
      }
    }
    ++v3;
  }
  while ( v3 != 7 );
  v13 = ipa3_ctx;
  if ( v4 != 7 && *(_DWORD *)(ipa3_ctx + 50136) != *(_DWORD *)(ipa3_ctx + 50140) )
    return 0;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d All %d CBs probed\n", "ipa_smmu_update_fw_loader", 11711, 7);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d All %d CBs probed\n", "ipa_smmu_update_fw_loader", 11711, 7);
      v13 = ipa3_ctx;
    }
  }
  if ( *(_BYTE *)(v13 + 32271) != 1 )
  {
    ipa_fw_load_sm_handle_event(1);
    return 0;
  }
  printk(&unk_3E5B32, "ipa_smmu_update_fw_loader");
  v16 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v17 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d Using XBL boot load for IPA FW\n", "ipa_smmu_update_fw_loader", 11714);
      v16 = ipa3_ctx;
    }
    v18 = *(_QWORD *)(v16 + 34160);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d Using XBL boot load for IPA FW\n", "ipa_smmu_update_fw_loader", 11714);
      v16 = ipa3_ctx;
    }
  }
  mutex_lock(v16 + 45152);
  v19 = ipa3_ctx + 45152;
  *(_DWORD *)(ipa3_ctx + 45144) = 4;
  v20 = mutex_unlock(v19);
  v21 = ipa3_attach_to_smmu(v20);
  if ( v21 )
  {
    v22 = v21;
    printk(&unk_3BD56D, "ipa_smmu_update_fw_loader");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d IPA attach to smmu failed %d\n", "ipa_smmu_update_fw_loader", 11722, v22);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d IPA attach to smmu failed %d\n", "ipa_smmu_update_fw_loader", 11722, v22);
    }
    return v22;
  }
  result = ipa3_post_init();
  if ( (_DWORD)result )
  {
    v22 = result;
    printk(&unk_3B77E6, "ipa_smmu_update_fw_loader");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d IPA post init failed %d\n", "ipa_smmu_update_fw_loader", 11728, v22);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
        ipc_log_string(v25, "ipa %s:%d IPA post init failed %d\n", "ipa_smmu_update_fw_loader", 11728, v22);
    }
    return v22;
  }
  return result;
}
