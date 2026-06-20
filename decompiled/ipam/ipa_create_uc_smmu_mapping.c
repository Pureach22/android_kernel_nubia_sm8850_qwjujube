__int64 __fastcall ipa_create_uc_smmu_mapping(
        unsigned int a1,
        char a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        long double a6,
        long double a7,
        long double a8,
        long double a9,
        float a10,
        __int64 a11,
        unsigned __int64 *a12)
{
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 result; // x0
  char *smmu_ctx; // x0
  char *v22; // x21
  __int64 v23; // x8
  unsigned __int64 v24; // x24
  unsigned __int64 v25; // x25
  __int64 v26; // x26
  int v27; // w28
  const void *v28; // x0
  int v29; // w8
  __int64 v30; // x23
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x20
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    if ( !*(_BYTE *)(ipa3_ctx + 43313) )
    {
      if ( a1 > 0xB )
        goto LABEL_23;
      if ( ((1 << a1) & 0x305) != 0 )
      {
        smmu_ctx = ipa3_get_smmu_ctx(3u, a6, a7, a8, a9, a10);
        if ( (*smmu_ctx & 1) != 0 )
        {
          if ( a4 )
          {
            v22 = smmu_ctx;
            v23 = *((_QWORD *)smmu_ctx + 3) + 4095LL;
            v24 = v23 & 0xFFFFFFFFFFFFF000LL;
            v25 = v23 & 0xFFFFFFFFFFFFF000LL;
            if ( !*(_DWORD *)(a4 + 8) )
            {
LABEL_22:
              *((_QWORD *)v22 + 3) = v25;
              *a12 = v24;
              ((void (__fastcall *)(_QWORD, __int64, unsigned __int64))ipa_save_uc_smmu_mapping_sgt)(a1, a4, v24);
              result = 0;
              goto LABEL_60;
            }
            v26 = *(_QWORD *)a4;
            v27 = 0;
            v25 = v23 & 0xFFFFFFFFFFFFF000LL;
            while ( 1 )
            {
              v28 = *((const void **)v22 + 2);
              v29 = *(_DWORD *)(v26 + 8) + *(_DWORD *)(v26 + 12);
              v50[0] = *(_QWORD *)(v26 + 16);
              v30 = (v29 + 4095) & 0xFFFFF000;
              if ( (unsigned int)ipa3_iommu_map(v28, v25, v50[0], v30, 3u) )
                break;
              v25 += v30;
              ++v27;
              ++*(_DWORD *)(ipa3_ctx + 43320);
              v26 = sg_next(v26);
              if ( (unsigned int)v27 >= *(_DWORD *)(a4 + 8) )
                goto LABEL_22;
            }
            printk(&unk_3E1896, "ipa_create_uc_smmu_mapping_sgt");
            v43 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v44 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v44 )
              {
                ipc_log_string(
                  v44,
                  "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
                  "ipa_create_uc_smmu_mapping_sgt",
                  725,
                  v50,
                  v30);
                v43 = ipa3_ctx;
              }
              v45 = *(_QWORD *)(v43 + 34160);
              if ( v45 )
                ipc_log_string(
                  v45,
                  "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
                  "ipa_create_uc_smmu_mapping_sgt",
                  725,
                  v50,
                  v30);
            }
            if ( v27 >= 1 )
            {
              v46 = *(_QWORD *)a4;
              do
              {
                iommu_unmap(*((_QWORD *)v22 + 2), *(_QWORD *)(v46 + 16), *(unsigned int *)(v46 + 24));
                --v27;
                v46 = sg_next(v46);
              }
              while ( v27 );
            }
          }
          else
          {
            printk(&unk_3D06D6, "ipa_create_uc_smmu_mapping_sgt");
            v40 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v41 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v41 )
              {
                ipc_log_string(
                  v41,
                  "ipa %s:%d Bad parameters, scatter / gather list is NULL\n",
                  "ipa_create_uc_smmu_mapping_sgt",
                  713);
                v40 = ipa3_ctx;
              }
              v42 = *(_QWORD *)(v40 + 34160);
              if ( v42 )
                ipc_log_string(
                  v42,
                  "ipa %s:%d Bad parameters, scatter / gather list is NULL\n",
                  "ipa_create_uc_smmu_mapping_sgt",
                  713);
            }
          }
        }
        else
        {
          printk(&unk_3E181F, "ipa_create_uc_smmu_mapping_sgt");
          v37 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v38 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v38 )
            {
              ipc_log_string(v38, "ipa %s:%d No SMMU CB setup\n", "ipa_create_uc_smmu_mapping_sgt", 709);
              v37 = ipa3_ctx;
            }
            v39 = *(_QWORD *)(v37 + 34160);
            if ( v39 )
              ipc_log_string(v39, "ipa %s:%d No SMMU CB setup\n", "ipa_create_uc_smmu_mapping_sgt", 709);
          }
        }
        printk(&unk_3EA160, "ipa_create_uc_smmu_mapping");
        v47 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v48 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v48 )
          {
            ipc_log_string(v48, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 926, a1);
            v47 = ipa3_ctx;
          }
          v49 = *(_QWORD *)(v47 + 34160);
          if ( v49 )
            ipc_log_string(v49, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 926, a1);
        }
        __break(0x800u);
        goto LABEL_59;
      }
      if ( ((1 << a1) & 0xC0A) == 0 )
      {
LABEL_23:
        result = 0;
        __break(0x800u);
        goto LABEL_60;
      }
      if ( (unsigned int)ipa_create_uc_smmu_mapping_pa(a3, a5, a1 == 10, a12) )
      {
        printk(&unk_3EA160, "ipa_create_uc_smmu_mapping");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 915, a1);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 915, a1);
        }
LABEL_59:
        result = 4294967282LL;
        goto LABEL_60;
      }
      goto LABEL_15;
    }
    printk(&unk_3D8F03, "ipa_create_uc_smmu_mapping");
    v31 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_29;
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(v32, "ipa %s:%d Unsupported SMMU pairing\n", "ipa_create_uc_smmu_mapping", 883);
      v31 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v31 + 34160);
    if ( v33 )
    {
      ipc_log_string(v33, "ipa %s:%d Unsupported SMMU pairing\n", "ipa_create_uc_smmu_mapping", 883);
      result = 4294967274LL;
    }
    else
    {
LABEL_29:
      result = 4294967274LL;
    }
  }
  else
  {
    if ( !*(_BYTE *)(ipa3_ctx + 43313) )
    {
      if ( (unsigned int)ipa_create_uc_smmu_mapping_pa(a3, a5, a1 == 10, a12) )
      {
        printk(&unk_3EA160, "ipa_create_uc_smmu_mapping");
        v34 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v35 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v35 )
          {
            ipc_log_string(v35, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 897, a1);
            v34 = ipa3_ctx;
          }
          v36 = *(_QWORD *)(v34 + 34160);
          if ( v36 )
            ipc_log_string(v36, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_uc_smmu_mapping", 897, a1);
        }
        goto LABEL_59;
      }
LABEL_15:
      ipa_save_uc_smmu_mapping_pa(a1, a3, *a12, a5);
      result = 0;
      goto LABEL_60;
    }
    result = 0;
    *a12 = a3;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
