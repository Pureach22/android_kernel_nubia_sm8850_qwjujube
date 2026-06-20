__int64 __fastcall ipa_create_uc_smmu_mapping_pa(
        __int64 a1,
        __int64 a2,
        char a3,
        _QWORD *a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        float a9)
{
  char *smmu_ctx; // x0
  char *v14; // x22
  const void *v15; // x0
  char *v16; // t2
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned int v19; // w4
  unsigned __int64 v20; // x24
  unsigned __int64 v21; // x19
  __int64 result; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = a1;
  smmu_ctx = ipa3_get_smmu_ctx(3u, a5, a6, a7, a8, a9);
  if ( (*smmu_ctx & 1) == 0 )
  {
    printk(&unk_3E181F, "ipa_create_uc_smmu_mapping_pa");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d No SMMU CB setup\n", "ipa_create_uc_smmu_mapping_pa", 611);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d No SMMU CB setup\n", "ipa_create_uc_smmu_mapping_pa", 611);
        result = 4294967274LL;
        goto LABEL_7;
      }
    }
LABEL_18:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v14 = smmu_ctx;
  v16 = smmu_ctx + 16;
  v15 = *((const void **)smmu_ctx + 2);
  v17 = *((_QWORD *)v16 + 1) + 4095LL;
  v18 = a2 + a1 - (a1 & 0xFFFFFFFFFFFFF000LL) + 4095;
  if ( (a3 & 1) != 0 )
    v19 = 19;
  else
    v19 = 3;
  v20 = v17 & 0xFFFFFFFFFFFFF000LL;
  v21 = v18 & 0xFFFFFFFFFFFFF000LL;
  result = ipa3_iommu_map(v15, v17 & 0xFFFFFFFFFFFFF000LL, a1 & 0xFFFFFFFFFFFFF000LL, v18 & 0xFFFFFFFFFFFFF000LL, v19);
  if ( (_DWORD)result )
  {
    printk(&unk_3E1896, "ipa_create_uc_smmu_mapping_pa");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(
          v27,
          "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
          "ipa_create_uc_smmu_mapping_pa",
          619,
          v29,
          v21);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(
          v28,
          "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
          "ipa_create_uc_smmu_mapping_pa",
          619,
          v29,
          v21);
    }
    goto LABEL_18;
  }
  ++*(_DWORD *)(ipa3_ctx + 43320);
  *((_QWORD *)v14 + 3) = v21 + v20;
  *a4 = v20 + a1 - (a1 & 0xFFFFFFFFFFFFF000LL);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
