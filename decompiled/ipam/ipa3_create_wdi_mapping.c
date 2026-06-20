__int64 __fastcall ipa3_create_wdi_mapping(
        int a1,
        __int64 a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        float a7)
{
  char *smmu_ctx; // x0
  char *v10; // x21
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int v21; // w22
  __int64 v22; // x27
  __int64 v23; // x0

  smmu_ctx = ipa3_get_smmu_ctx(1u, a3, a4, a5, a6, a7);
  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_create_wdi_mapping__rs, "ipa3_create_wdi_mapping") )
      printk(&unk_3BBCB6, "ipa3_create_wdi_mapping");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d info = %pK\n", "ipa3_create_wdi_mapping", 3299, nullptr);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d info = %pK\n", "ipa3_create_wdi_mapping", 3299, nullptr);
    }
    return 4294967274LL;
  }
  v10 = smmu_ctx;
  if ( (*smmu_ctx & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_create_wdi_mapping__rs_180, "ipa3_create_wdi_mapping") )
      printk(&unk_3E181F, "ipa3_create_wdi_mapping");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d No SMMU CB setup\n", "ipa3_create_wdi_mapping", 3304);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d No SMMU CB setup\n", "ipa3_create_wdi_mapping", 3304);
    }
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 43311) & 1) != 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_create_wdi_mapping__rs_183, "ipa3_create_wdi_mapping") )
    {
      printk(&unk_3A4536, "ipa3_create_wdi_mapping");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_6;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_6:
        v12 = *(_QWORD *)(v11 + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d IPA SMMU not enabled\n", "ipa3_create_wdi_mapping", 3309);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d IPA SMMU not enabled\n", "ipa3_create_wdi_mapping", 3309);
      }
    }
    return 4294967274LL;
  }
  if ( a1 )
  {
    v21 = 0;
    do
    {
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v23 )
          ipc_log_string(
            v23,
            "ipa %s:%d i=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
            "ipa3_create_wdi_mapping",
            3315,
            v21,
            (const void *)(a2 + 32LL * v21),
            *(_QWORD *)(a2 + 32LL * v21 + 8),
            *(_QWORD *)(a2 + 32LL * v21 + 16));
      }
      v22 = a2 + 32LL * v21++;
      *(_DWORD *)(v22 + 24) = ipa3_iommu_map(
                                *((const void **)v10 + 2),
                                *(_QWORD *)(v22 + 8) & 0xFFFFFFFFFFFFF000LL,
                                *(_QWORD *)v22 & 0xFFFFFFFFFFFFF000LL,
                                (*(_QWORD *)v22 + *(_QWORD *)(v22 + 16) - (*(_QWORD *)v22 & 0xFFFFFFFFFFFFF000LL) + 4095)
                              & 0xFFFFFFFFFFFFF000LL,
                                3u);
    }
    while ( a1 != v21 );
  }
  return 0;
}
