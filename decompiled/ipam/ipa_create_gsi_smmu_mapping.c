__int64 __fastcall ipa_create_gsi_smmu_mapping(
        unsigned int a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        long double a6,
        long double a7,
        long double a8,
        long double a9,
        float a10,
        __int64 a11,
        __int64 *a12)
{
  char *smmu_ctx; // x0
  char *v18; // x21
  __int64 v19; // x8
  unsigned __int64 v20; // x23
  __int64 v21; // x0
  unsigned __int64 v22; // x24
  unsigned int v23; // w25
  unsigned int v24; // w8
  __int64 v25; // x9
  unsigned __int64 v26; // x25
  __int64 v27; // x26
  int v28; // w28
  const void *v29; // x0
  int v30; // w8
  __int64 v31; // x24
  __int64 result; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  _BOOL8 v38; // x2
  unsigned __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x20
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59[2]; // [xsp+0h] [xbp-10h] BYREF

  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    if ( !*(_BYTE *)(ipa3_ctx + 43310) )
    {
      if ( a1 > 0x13 )
      {
        result = 0;
        __break(0x800u);
        goto LABEL_38;
      }
      if ( ((1 << a1) & 0x33355) != 0 )
      {
        smmu_ctx = ipa3_get_smmu_ctx(0, a6, a7, a8, a9, a10);
        if ( (*smmu_ctx & 1) != 0 )
        {
          if ( a4 )
          {
            v18 = smmu_ctx;
            v19 = *((_QWORD *)smmu_ctx + 3) + 4095LL;
            v20 = v19 & 0xFFFFFFFFFFFFF000LL;
            if ( *(_DWORD *)(a4 + 8) )
            {
              v21 = *(_QWORD *)a4;
              v22 = 0;
              v23 = 0;
              do
              {
                ++v23;
                v22 += (*(_DWORD *)(v21 + 8) + *(_DWORD *)(v21 + 12) + 4095) & 0xFFFFF000;
                v21 = sg_next(v21);
                v24 = *(_DWORD *)(a4 + 8);
              }
              while ( v23 < v24 );
              if ( v22 > 0x1000 )
              {
                v25 = 1LL << -(char)__clz(v22 - 1);
                v20 = (*((_QWORD *)v18 + 3) + v25 - 1) & -v25;
              }
              v26 = v20;
              if ( v24 )
              {
                v27 = *(_QWORD *)a4;
                v28 = 0;
                v26 = v20;
                while ( 1 )
                {
                  v29 = *((const void **)v18 + 2);
                  v30 = *(_DWORD *)(v27 + 8) + *(_DWORD *)(v27 + 12);
                  v59[0] = *(_QWORD *)(v27 + 16);
                  v31 = (v30 + 4095) & 0xFFFFF000;
                  if ( (unsigned int)ipa3_iommu_map(v29, v26, v59[0], v31, 3u) )
                    break;
                  v26 += v31;
                  ++v28;
                  ++*(_DWORD *)(ipa3_ctx + 43320);
                  v27 = sg_next(v27);
                  if ( (unsigned int)v28 >= *(_DWORD *)(a4 + 8) )
                    goto LABEL_34;
                }
                printk(&unk_3E1896, "ipa_create_ap_smmu_mapping_sgt");
                v52 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v53 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v53 )
                  {
                    ipc_log_string(
                      v53,
                      "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
                      "ipa_create_ap_smmu_mapping_sgt",
                      670,
                      v59,
                      v31);
                    v52 = ipa3_ctx;
                  }
                  v54 = *(_QWORD *)(v52 + 34160);
                  if ( v54 )
                    ipc_log_string(
                      v54,
                      "ipa %s:%d iommu map failed for pa=%pa len=%zu\n",
                      "ipa_create_ap_smmu_mapping_sgt",
                      670,
                      v59,
                      v31);
                }
                if ( v28 >= 1 )
                {
                  v55 = *(_QWORD *)a4;
                  do
                  {
                    iommu_unmap(*((_QWORD *)v18 + 2), *(_QWORD *)(v55 + 16), *(unsigned int *)(v55 + 24));
                    --v28;
                    v55 = sg_next(v55);
                  }
                  while ( v28 );
                }
                goto LABEL_69;
              }
            }
            else
            {
              v26 = v19 & 0xFFFFFFFFFFFFF000LL;
            }
LABEL_34:
            v39 = *((unsigned int *)v18 + 12);
            *((_QWORD *)v18 + 3) = v26;
            if ( v26 >= v39 )
              *((_QWORD *)v18 + 3) = *((unsigned int *)v18 + 10);
            *a12 = v20;
            ((void (__fastcall *)(_QWORD, __int64, unsigned __int64))ipa_save_uc_smmu_mapping_sgt)(a1, a4, v20);
            goto LABEL_37;
          }
          printk(&unk_3D06D6, "ipa_create_ap_smmu_mapping_sgt");
          v49 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v50 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v50 )
            {
              ipc_log_string(
                v50,
                "ipa %s:%d Bad parameters, scatter / gather list is NULL\n",
                "ipa_create_ap_smmu_mapping_sgt",
                647);
              v49 = ipa3_ctx;
            }
            v51 = *(_QWORD *)(v49 + 34160);
            if ( v51 )
              ipc_log_string(
                v51,
                "ipa %s:%d Bad parameters, scatter / gather list is NULL\n",
                "ipa_create_ap_smmu_mapping_sgt",
                647);
          }
        }
        else
        {
          printk(&unk_3E181F, "ipa_create_ap_smmu_mapping_sgt");
          v43 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v44 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v44 )
            {
              ipc_log_string(v44, "ipa %s:%d No SMMU CB setup\n", "ipa_create_ap_smmu_mapping_sgt", 643);
              v43 = ipa3_ctx;
            }
            v45 = *(_QWORD *)(v43 + 34160);
            if ( v45 )
              ipc_log_string(v45, "ipa %s:%d No SMMU CB setup\n", "ipa_create_ap_smmu_mapping_sgt", 643);
          }
        }
LABEL_69:
        printk(&unk_3EA160, "ipa_create_gsi_smmu_mapping");
        v56 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v57 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v57 )
          {
            ipc_log_string(v57, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1045, a1);
            v56 = ipa3_ctx;
          }
          v58 = *(_QWORD *)(v56 + 34160);
          if ( v58 )
            ipc_log_string(v58, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1045, a1);
        }
LABEL_74:
        result = 4294967282LL;
        goto LABEL_38;
      }
      v38 = a1 == 10 || a1 == 18;
      if ( (unsigned int)ipa_create_ap_smmu_mapping_pa(a3, a5, v38, a12) )
      {
        printk(&unk_3EA160, "ipa_create_gsi_smmu_mapping");
        v46 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v47 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v47 )
          {
            ipc_log_string(v47, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1027, a1);
            v46 = ipa3_ctx;
          }
          v48 = *(_QWORD *)(v46 + 34160);
          if ( v48 )
            ipc_log_string(v48, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1027, a1);
        }
        goto LABEL_74;
      }
LABEL_32:
      ipa_save_uc_smmu_mapping_pa(a1, a3, *a12, a5);
LABEL_37:
      result = 0;
      goto LABEL_38;
    }
    printk(&unk_3D8F03, "ipa_create_gsi_smmu_mapping");
    v40 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_45;
    v41 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v41 )
    {
      ipc_log_string(v41, "ipa %s:%d Unsupported SMMU pairing\n", "ipa_create_gsi_smmu_mapping", 986);
      v40 = ipa3_ctx;
    }
    v42 = *(_QWORD *)(v40 + 34160);
    if ( v42 )
    {
      ipc_log_string(v42, "ipa %s:%d Unsupported SMMU pairing\n", "ipa_create_gsi_smmu_mapping", 986);
      result = 4294967274LL;
    }
    else
    {
LABEL_45:
      result = 4294967274LL;
    }
  }
  else
  {
    if ( !*(_BYTE *)(ipa3_ctx + 43310) )
    {
      if ( (unsigned int)ipa_create_ap_smmu_mapping_pa(a3, a5, a1 == 10, a12) )
      {
        printk(&unk_3EA160, "ipa_create_gsi_smmu_mapping");
        v33 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v34 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v34 )
          {
            ipc_log_string(v34, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1002, a1);
            v33 = ipa3_ctx;
          }
          v35 = *(_QWORD *)(v33 + 34160);
          if ( v35 )
            ipc_log_string(v35, "ipa %s:%d Fail to create mapping res %d\n", "ipa_create_gsi_smmu_mapping", 1002, a1);
        }
        goto LABEL_74;
      }
      goto LABEL_32;
    }
    result = 0;
    *a12 = a3;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
