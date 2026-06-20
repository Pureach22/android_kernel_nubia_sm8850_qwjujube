__int64 __fastcall ipa_create_ap_smmu_mapping_pa(
        __int64 a1,
        unsigned __int64 a2,
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
  __int64 v15; // x8
  unsigned __int64 v16; // x19
  unsigned __int64 v17; // x24
  const void *v18; // x0
  unsigned int v19; // w4
  unsigned __int64 v20; // x8
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = a1;
  smmu_ctx = ipa3_get_smmu_ctx(0, a5, a6, a7, a8, a9);
  if ( (*smmu_ctx & 1) == 0 )
  {
    printk(&unk_3E181F, "ipa_create_ap_smmu_mapping_pa");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d No SMMU CB setup\n", "ipa_create_ap_smmu_mapping_pa", 577);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d No SMMU CB setup\n", "ipa_create_ap_smmu_mapping_pa", 577);
        result = 4294967274LL;
        goto LABEL_12;
      }
    }
LABEL_23:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v14 = smmu_ctx;
  v15 = *((_QWORD *)smmu_ctx + 3);
  v16 = (a2 + a1 - (a1 & 0xFFFFFFFFFFFFF000LL) + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( a2 <= 0x1000 )
    v17 = (v15 + 4095) & 0xFFFFFFFFFFFFF000LL;
  else
    v17 = (a2 + v15 - 1) / a2 * a2;
  v18 = *((const void **)smmu_ctx + 2);
  if ( (a3 & 1) != 0 )
    v19 = 19;
  else
    v19 = 3;
  if ( (unsigned int)ipa3_iommu_map(v18, v17, a1 & 0xFFFFFFFFFFFFF000LL, v16, v19) )
  {
    printk(&unk_3E1896, "ipa_create_ap_smmu_mapping_pa");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(
          v26,
          "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
          "ipa_create_ap_smmu_mapping_pa",
          588,
          v28,
          v16);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(
          v27,
          "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
          "ipa_create_ap_smmu_mapping_pa",
          588,
          v28,
          v16);
    }
    goto LABEL_23;
  }
  ++*(_DWORD *)(ipa3_ctx + 43320);
  v20 = *((unsigned int *)v14 + 12);
  *((_QWORD *)v14 + 3) = v17 + v16;
  if ( v17 + v16 >= v20 )
    *((_QWORD *)v14 + 3) = *((unsigned int *)v14 + 10);
  result = 0;
  *a4 = v17 + a1 - (a1 & 0xFFFFFFFFFFFFF000LL);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
