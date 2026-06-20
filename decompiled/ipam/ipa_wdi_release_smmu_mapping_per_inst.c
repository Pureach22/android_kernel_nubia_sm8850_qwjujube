__int64 __fastcall ipa_wdi_release_smmu_mapping_per_inst(
        unsigned int a1,
        int a2,
        __int64 a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        float a8)
{
  __int64 v8; // x8
  unsigned int v11; // w0
  char *smmu_ctx; // x0
  char *v13; // x21
  int v14; // w22
  __int64 v15; // x0
  __int64 v16; // x25
  __int64 v17; // x25
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0

  if ( !a3 )
  {
    if ( (unsigned int)__ratelimit(&ipa_wdi_release_smmu_mapping_per_inst__rs, "ipa_wdi_release_smmu_mapping_per_inst") )
      printk(&unk_3BBCB6, "ipa_wdi_release_smmu_mapping_per_inst");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d info = %pK\n", "ipa_wdi_release_smmu_mapping_per_inst", 1063, nullptr);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d info = %pK\n", "ipa_wdi_release_smmu_mapping_per_inst", 1063, nullptr);
    }
    return 4294967274LL;
  }
  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_release_smmu_mapping_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_release_smmu_mapping_per_inst", 1068, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_release_smmu_mapping_per_inst",
        1068,
        a1);
    }
    return 4294967282LL;
  }
  else
  {
    v8 = ipa_wdi_ctx_list[a1];
    if ( v8 )
    {
      if ( (unsigned int)(*(_DWORD *)(v8 + 184) + 1) < 2 )
        v11 = 1;
      else
        v11 = 2;
      smmu_ctx = ipa3_get_smmu_ctx(v11, a4, a5, a6, a7, a8);
      if ( *smmu_ctx == 1 )
      {
        if ( a2 )
        {
          v13 = smmu_ctx;
          v14 = 0;
          do
          {
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v15 = ipa3_get_ipc_logbuf_low();
              v16 = v14;
              ipc_log_string(
                v15,
                "ipa_wdi %s:%d i=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
                "ipa_wdi_release_smmu_mapping_per_inst",
                1089,
                v14,
                (const void *)(a3 + 32LL * v14),
                *(_QWORD *)(a3 + 32LL * v14 + 8),
                *(_QWORD *)(a3 + 32LL * v14 + 16));
            }
            else
            {
              v16 = v14;
            }
            v17 = a3 + 32 * v16;
            ++v14;
            *(_DWORD *)(v17 + 24) = iommu_unmap(
                                      *((_QWORD *)v13 + 2),
                                      *(_QWORD *)(v17 + 8) & 0xFFFFFFFFFFFFF000LL,
                                      (*(_QWORD *)(v17 + 16)
                                     + *(_QWORD *)v17
                                     - (*(_QWORD *)v17 & 0xFFFFFFFFFFFFF000LL)
                                     + 4095)
                                    & 0xFFFFFFFFFFFFF000LL);
          }
          while ( a2 != v14 );
        }
        return 0;
      }
      printk(&unk_3A8692, "ipa_wdi_release_smmu_mapping_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(v27, "ipa_wdi %s:%d No SMMU CB setup\n", "ipa_wdi_release_smmu_mapping_per_inst", 1083);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v28 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v28, "ipa_wdi %s:%d No SMMU CB setup\n", "ipa_wdi_release_smmu_mapping_per_inst", 1083);
      }
      return 4294967274LL;
    }
    printk(&unk_3F0CD4, "ipa_wdi_release_smmu_mapping_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_release_smmu_mapping_per_inst", 1073);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_release_smmu_mapping_per_inst", 1073);
    }
    return 0xFFFFFFFFLL;
  }
}
