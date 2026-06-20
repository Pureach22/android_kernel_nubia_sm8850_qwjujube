__int64 __fastcall ipa_wdi_create_smmu_mapping_per_inst(
        unsigned int a1,
        int a2,
        __int64 a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        float a8)
{
  __int64 v9; // x8
  unsigned int v12; // w0
  char *smmu_ctx; // x0
  char *v14; // x21
  int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  int v20; // w22
  __int64 v21; // x0
  __int64 v22; // x25
  __int64 v23; // x25
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0

  if ( !a3 )
  {
    if ( (unsigned int)__ratelimit(&ipa_wdi_create_smmu_mapping_per_inst__rs, "ipa_wdi_create_smmu_mapping_per_inst") )
      printk(&unk_3BBCB6, "ipa_wdi_create_smmu_mapping_per_inst");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d info = %pK\n", "ipa_wdi_create_smmu_mapping_per_inst", 998, nullptr);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d info = %pK\n", "ipa_wdi_create_smmu_mapping_per_inst", 998, nullptr);
    }
    return 4294967274LL;
  }
  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_create_smmu_mapping_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_create_smmu_mapping_per_inst", 1003, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_create_smmu_mapping_per_inst",
        1003,
        a1);
    }
    return 4294967282LL;
  }
  else
  {
    v9 = ipa_wdi_ctx_list[a1];
    if ( v9 )
    {
      if ( (unsigned int)(*(_DWORD *)(v9 + 184) + 1) < 2 )
        v12 = 1;
      else
        v12 = 2;
      smmu_ctx = ipa3_get_smmu_ctx(v12, a4, a5, a6, a7, a8);
      if ( (*smmu_ctx & 1) == 0 )
      {
        printk(&unk_3A8692, "ipa_wdi_create_smmu_mapping_per_inst");
        if ( ipa3_get_ipc_logbuf() )
        {
          v28 = ipa3_get_ipc_logbuf();
          ipc_log_string(v28, "ipa_wdi %s:%d No SMMU CB setup\n", "ipa_wdi_create_smmu_mapping_per_inst", 1018);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v29 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v29, "ipa_wdi %s:%d No SMMU CB setup\n", "ipa_wdi_create_smmu_mapping_per_inst", 1018);
        }
        return 4294967274LL;
      }
      v14 = smmu_ctx;
      v15 = *(_DWORD *)(ipa_wdi_ctx_list[a1] + 184);
      if ( (unsigned int)(v15 + 1) >= 2 )
      {
        if ( v15 == 1 && *(_BYTE *)(ipa3_ctx + 43312) == 1 )
          goto LABEL_42;
      }
      else if ( (*(_BYTE *)(ipa3_ctx + 43311) & 1) != 0 )
      {
LABEL_42:
        printk(&unk_3F9DAA, "ipa_wdi_create_smmu_mapping_per_inst");
        if ( ipa3_get_ipc_logbuf() )
        {
          v30 = ipa3_get_ipc_logbuf();
          ipc_log_string(v30, "ipa_wdi %s:%d IPA SMMU not enabled\n", "ipa_wdi_create_smmu_mapping_per_inst", 1026);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v31 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v31, "ipa_wdi %s:%d IPA SMMU not enabled\n", "ipa_wdi_create_smmu_mapping_per_inst", 1026);
        }
        return 4294967274LL;
      }
      if ( a2 )
      {
        v20 = 0;
        do
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            v22 = v20;
            ipc_log_string(
              v21,
              "ipa_wdi %s:%d i=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
              "ipa_wdi_create_smmu_mapping_per_inst",
              1032,
              v20,
              (const void *)(a3 + 32LL * v20),
              *(_QWORD *)(a3 + 32LL * v20 + 8),
              *(_QWORD *)(a3 + 32LL * v20 + 16));
          }
          else
          {
            v22 = v20;
          }
          v23 = a3 + 32 * v22;
          ++v20;
          *(_DWORD *)(v23 + 24) = ipa3_iommu_map(
                                    *((const void **)v14 + 2),
                                    *(_QWORD *)(v23 + 8) & 0xFFFFFFFFFFFFF000LL,
                                    *(_QWORD *)v23 & 0xFFFFFFFFFFFFF000LL,
                                    (*(_QWORD *)v23
                                   + *(_QWORD *)(v23 + 16)
                                   - (*(_QWORD *)v23 & 0xFFFFFFFFFFFFF000LL)
                                   + 4095)
                                  & 0xFFFFFFFFFFFFF000LL,
                                    3u);
        }
        while ( a2 != v20 );
      }
      return 0;
    }
    else
    {
      printk(&unk_3F0CD4, "ipa_wdi_create_smmu_mapping_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v26 = ipa3_get_ipc_logbuf();
        ipc_log_string(v26, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_create_smmu_mapping_per_inst", 1008);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v27 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v27, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_create_smmu_mapping_per_inst", 1008);
      }
      return 0xFFFFFFFFLL;
    }
  }
}
