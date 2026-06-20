__int64 __fastcall ipa3_release_wdi_mapping(
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
  int v11; // w22
  __int64 v12; // x27
  __int64 v13; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0

  smmu_ctx = ipa3_get_smmu_ctx(1u, a3, a4, a5, a6, a7);
  if ( !a2 )
  {
    printk(&unk_3BBCB6, "ipa3_release_wdi_mapping");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d info = %pK\n", "ipa3_release_wdi_mapping", 3335, nullptr);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d info = %pK\n", "ipa3_release_wdi_mapping", 3335, nullptr);
    }
    return 4294967274LL;
  }
  v10 = smmu_ctx;
  if ( *smmu_ctx != 1 )
  {
    printk(&unk_3E181F, "ipa3_release_wdi_mapping");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d No SMMU CB setup\n", "ipa3_release_wdi_mapping", 3340);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d No SMMU CB setup\n", "ipa3_release_wdi_mapping", 3340);
    }
    return 4294967274LL;
  }
  if ( a1 )
  {
    v11 = 0;
    do
    {
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v13 )
          ipc_log_string(
            v13,
            "ipa %s:%d i=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
            "ipa3_release_wdi_mapping",
            3346,
            v11,
            (const void *)(a2 + 32LL * v11),
            *(_QWORD *)(a2 + 32LL * v11 + 8),
            *(_QWORD *)(a2 + 32LL * v11 + 16));
      }
      v12 = a2 + 32LL * v11++;
      *(_DWORD *)(v12 + 24) = iommu_unmap(
                                *((_QWORD *)v10 + 2),
                                *(_QWORD *)(v12 + 8) & 0xFFFFFFFFFFFFF000LL,
                                (*(_QWORD *)(v12 + 16) + *(_QWORD *)v12 - (*(_QWORD *)v12 & 0xFFFFFFFFFFFFF000LL) + 4095)
                              & 0xFFFFFFFFFFFFF000LL);
    }
    while ( a1 != v11 );
  }
  return 0;
}
