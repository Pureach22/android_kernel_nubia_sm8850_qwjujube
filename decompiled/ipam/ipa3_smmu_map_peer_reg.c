__int64 __fastcall ipa3_smmu_map_peer_reg(unsigned __int64 a1, char a2, unsigned int a3)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  const void *smmu_domain_by_type; // x0
  const char *v10; // x19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  const char *v16; // x5
  const char *v17; // x5
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = a1;
  if ( a3 >= 7 )
  {
    printk(&unk_3B7A61, "ipa3_smmu_map_peer_reg");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d invalid cb_type\n", "ipa3_smmu_map_peer_reg", 370);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d invalid cb_type\n", "ipa3_smmu_map_peer_reg", 370);
    }
    goto LABEL_43;
  }
  v4 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + a3 + 43310) != 1 )
  {
    smmu_domain_by_type = (const void *)ipa3_get_smmu_domain_by_type(a3);
    if ( !smmu_domain_by_type )
    {
      printk(&unk_3DDF55, "ipa3_smmu_map_peer_reg");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_peer_reg", 381);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_peer_reg", 381);
      }
      goto LABEL_43;
    }
    if ( (a2 & 1) != 0 )
    {
      if ( (unsigned int)ipa3_iommu_map(smmu_domain_by_type, a1, a1, 4096, 0x13u) )
      {
LABEL_11:
        if ( (a2 & 1) != 0 )
          v10 = "map";
        else
          v10 = "unmap";
        printk(&unk_3F7531, "ipa3_smmu_map_peer_reg");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d Fail to %s reg 0x%pa\n", "ipa3_smmu_map_peer_reg", 394, v10, v24);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d Fail to %s reg 0x%pa\n", "ipa3_smmu_map_peer_reg", 394, v10, v24);
            result = 4294967274LL;
            goto LABEL_32;
          }
        }
LABEL_43:
        result = 4294967274LL;
        goto LABEL_32;
      }
    }
    else if ( (unsigned int)iommu_unmap(smmu_domain_by_type, a1, 4096) != 4096 )
    {
      goto LABEL_11;
    }
    v14 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_31;
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      if ( (a2 & 1) != 0 )
        v16 = "map";
      else
        v16 = "unmap";
      ipc_log_string(v15, "ipa %s:%d Peer reg 0x%pa %s\n", "ipa3_smmu_map_peer_reg", 398, v24, v16);
      v14 = ipa3_ctx;
    }
    result = *(_QWORD *)(v14 + 34160);
    if ( result )
    {
      if ( (a2 & 1) != 0 )
        v17 = "map";
      else
        v17 = "unmap";
      ipc_log_string(result, "ipa %s:%d Peer reg 0x%pa %s\n", "ipa3_smmu_map_peer_reg", 398, v24, v17);
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( !ipa3_ctx )
  {
LABEL_31:
    result = 0;
    goto LABEL_32;
  }
  v5 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v5 )
  {
    ipc_log_string(v5, "ipa %s:%d CB# %d is set to s1 bypass\n", "ipa3_smmu_map_peer_reg", 375, a3);
    v4 = ipa3_ctx;
  }
  result = *(_QWORD *)(v4 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d CB# %d is set to s1 bypass\n", "ipa3_smmu_map_peer_reg", 375, a3);
    goto LABEL_31;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
