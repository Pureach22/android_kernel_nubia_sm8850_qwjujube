unsigned __int64 *__fastcall ipa_save_uc_smmu_mapping_pa(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned __int64 *result; // x0
  unsigned __int64 *v11; // x5
  __int64 v12; // x8
  char *v13; // x23
  __int64 v14; // x9
  __int64 v15; // x8
  unsigned __int64 v16; // x7
  __int64 v17; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = ipa3_ctx;
  v18[0] = a2;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(
        v8,
        "ipa %s:%d --res_idx=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
        "ipa_save_uc_smmu_mapping_pa",
        824,
        a1,
        v18,
        a3,
        a4);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
      ipc_log_string(
        v9,
        "ipa %s:%d --res_idx=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
        "ipa_save_uc_smmu_mapping_pa",
        824,
        a1,
        v18,
        a3,
        a4);
  }
  result = (unsigned __int64 *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
  v11 = result;
  if ( a1 >= 0x14 )
  {
    __break(0x5512u);
    JUMPOUT(0x10F428);
  }
  v12 = 16LL * a1;
  v13 = (char *)&wdi_res + v12;
  *(_QWORD *)((char *)&wdi_res + v12) = result;
  if ( result )
  {
    if ( (v12 | 8uLL) > 0x140 || (*((_DWORD *)v13 + 2) = 1, (v12 | 0xCuLL) > 0x140) )
      __break(1u);
    v14 = v18[0];
    v13[12] = 1;
    *result = v14 & 0xFFFFFFFFFFFFF000LL;
    result[1] = a3 & 0xFFFFFFFFFFFFF000LL;
    v15 = ipa3_ctx;
    v16 = (a4 + v14 - (v14 & 0xFFFFFFFFFFFFF000LL) + 4095) & 0xFFFFFFFFFFFFF000LL;
    result[2] = v16;
    if ( v15 )
    {
      v17 = *(_QWORD *)(v15 + 34152);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d res_idx=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
          "ipa_save_uc_smmu_mapping_pa",
          839,
          a1,
          v11,
          a3 & 0xFFFFFFFFFFFFF000LL,
          v16);
        v15 = ipa3_ctx;
      }
      result = *(unsigned __int64 **)(v15 + 34160);
      if ( result )
        result = (unsigned __int64 *)ipc_log_string(
                                       result,
                                       "ipa %s:%d res_idx=%d pa=0x%pa iova=0x%lx sz=0x%zx\n",
                                       "ipa_save_uc_smmu_mapping_pa",
                                       839,
                                       a1,
                                       *(const void **)v13,
                                       *(_QWORD *)(*(_QWORD *)v13 + 8LL),
                                       *(_QWORD *)(*(_QWORD *)v13 + 16LL));
    }
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
