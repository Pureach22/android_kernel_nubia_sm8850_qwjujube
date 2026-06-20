__int64 __fastcall ipa3_iommu_map(const void *a1, unsigned __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  char *v19; // x8
  __int64 v20; // x1
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x4
  __int64 result; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x1
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  _QWORD v48[2]; // [xsp+0h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = ipa3_ctx;
  v48[0] = a3;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( !v10
      || (ipc_log_string(v10, "ipa %s:%d domain =0x%pK iova 0x%lx\n", "ipa3_iommu_map", 12168, a1, a2),
          (v9 = ipa3_ctx) != 0) )
    {
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d paddr =0x%pa size 0x%x\n", "ipa3_iommu_map", 12169, v48, a4);
    }
  }
  if ( smmu_cb[0] == 1 )
  {
    v12 = qword_1F7820;
  }
  else
  {
    printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 0);
        v12 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v12 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 0);
      v12 = 0;
    }
  }
  if ( (const void *)v12 == a1 )
    goto LABEL_35;
  if ( byte_1F7848 == 1 )
  {
    v13 = qword_1F7858;
  }
  else
  {
    printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 1);
        v13 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v13 + 34160);
      if ( v31 )
        ipc_log_string(v31, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 1);
      v13 = 0;
    }
  }
  if ( (const void *)v13 == a1 )
  {
LABEL_43:
    v19 = &byte_1F7848;
    goto LABEL_60;
  }
  if ( byte_1F7880 == 1 )
  {
    v14 = qword_1F7890;
  }
  else
  {
    printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 2);
        v14 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v14 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 2);
      v14 = 0;
    }
  }
  if ( (const void *)v14 == a1 )
  {
    v19 = &byte_1F7880;
  }
  else
  {
    if ( byte_1F7928 == 1 )
    {
      v15 = qword_1F7938;
    }
    else
    {
      printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v36 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v36 )
        {
          ipc_log_string(v36, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 5);
          v15 = ipa3_ctx;
        }
        v37 = *(_QWORD *)(v15 + 34160);
        if ( v37 )
          ipc_log_string(v37, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 5);
        v15 = 0;
      }
    }
    if ( (const void *)v15 == a1 )
    {
      v19 = &byte_1F7928;
    }
    else
    {
      if ( byte_1F7960 == 1 )
      {
        v16 = qword_1F7970;
      }
      else
      {
        printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v38 )
          {
            ipc_log_string(v38, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 6);
            v16 = ipa3_ctx;
          }
          v39 = *(_QWORD *)(v16 + 34160);
          if ( v39 )
            ipc_log_string(v39, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 6);
          v16 = 0;
        }
      }
      if ( (const void *)v16 == a1 )
      {
        v19 = &byte_1F7960;
      }
      else
      {
        if ( byte_1F78F0 == 1 )
        {
          v17 = qword_1F7900;
        }
        else
        {
          printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
          v17 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v40 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v40 )
            {
              ipc_log_string(v40, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 4);
              v17 = ipa3_ctx;
            }
            v41 = *(_QWORD *)(v17 + 34160);
            if ( v41 )
              ipc_log_string(v41, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 4);
            v17 = 0;
          }
        }
        if ( (const void *)v17 == a1 )
        {
          v19 = &byte_1F78F0;
        }
        else
        {
          if ( byte_1F78B8 == 1 )
          {
            v18 = qword_1F78C8;
          }
          else
          {
            printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
            v18 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v42 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v42 )
              {
                ipc_log_string(v42, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 3);
                v18 = ipa3_ctx;
              }
              v43 = *(_QWORD *)(v18 + 34160);
              if ( v43 )
                ipc_log_string(v43, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 3);
              v18 = 0;
            }
          }
          if ( (const void *)v18 != a1 )
          {
            printk(&unk_3BA6C6, "ipa3_iommu_map");
            v45 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v46 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v46 )
              {
                ipc_log_string(v46, "ipa %s:%d Unexpected domain 0x%pK\n", "ipa3_iommu_map", 12202, a1);
                v45 = ipa3_ctx;
              }
              v47 = *(_QWORD *)(v45 + 34160);
              if ( v47 )
                ipc_log_string(v47, "ipa %s:%d Unexpected domain 0x%pK\n", "ipa3_iommu_map", 12202, a1);
            }
            printk(&unk_3AED39, v44);
            __break(0x800u);
          }
          v19 = &byte_1F78B8;
          if ( (unsigned int)qword_1F78D8 <= a2 && (unsigned int)dword_1F78E0 > a2 )
          {
            printk(&unk_3BA69D, "ipa3_iommu_map");
            v21 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v22 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v22 )
              {
                ipc_log_string(v22, "ipa %s:%d iommu uC overlap addr 0x%lx\n", "ipa3_iommu_map", 12197, a2);
                v21 = ipa3_ctx;
              }
              v23 = *(_QWORD *)(v21 + 34160);
              if ( v23 )
                ipc_log_string(v23, "ipa %s:%d iommu uC overlap addr 0x%lx\n", "ipa3_iommu_map", 12197, a2);
            }
            printk(&unk_3AED39, v20);
            __break(0x800u);
LABEL_35:
            v19 = smmu_cb;
            if ( (unsigned int)qword_1F7830 > a2 || (unsigned int)dword_1F7838 <= a2 )
              goto LABEL_60;
            printk(&unk_3A5F98, "ipa3_iommu_map");
            v25 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v26 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v26 )
              {
                ipc_log_string(v26, "ipa %s:%d iommu AP overlap addr 0x%lx\n", "ipa3_iommu_map", 12175, a2);
                v25 = ipa3_ctx;
              }
              v27 = *(_QWORD *)(v25 + 34160);
              if ( v27 )
                ipc_log_string(v27, "ipa %s:%d iommu AP overlap addr 0x%lx\n", "ipa3_iommu_map", 12175, a2);
            }
            printk(&unk_3AED39, v24);
            __break(0x800u);
            goto LABEL_43;
          }
        }
      }
    }
  }
LABEL_60:
  if ( v19[53] )
    v32 = a5 | 4;
  else
    v32 = a5;
  result = iommu_map(a1, a2, v48[0], a4, v32, 2080);
  _ReadStatusReg(SP_EL0);
  return result;
}
