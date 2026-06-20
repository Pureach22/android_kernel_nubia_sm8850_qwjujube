__int64 __fastcall ipa3_smmu_map_peer_buff(__int64 a1, unsigned int a2, char a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x0
  unsigned int v9; // w23
  const void *smmu_domain_by_type; // x0
  const void *v15; // x22
  __int64 v16; // x24
  unsigned int v17; // w19
  unsigned __int64 v18; // x23
  __int64 v19; // x25
  __int64 v20; // x26
  unsigned int v21; // w27
  unsigned __int64 v22; // x24
  __int64 v23; // x28
  int v24; // w25
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  const char *v33; // x4
  __int64 v34; // x0
  const char *v35; // x4
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  char v49; // [xsp+4h] [xbp-1Ch]
  __int64 v50; // [xsp+8h] [xbp-18h]
  __int64 v51[2]; // [xsp+10h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  if ( a5 >= 7 )
  {
    printk(&unk_3B7A61, "ipa3_smmu_map_peer_buff");
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d invalid cb_type\n", "ipa3_smmu_map_peer_buff", 418);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d invalid cb_type\n", "ipa3_smmu_map_peer_buff", 418);
    }
    goto LABEL_67;
  }
  v5 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + a5 + 43310) == 1 )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        v7 = a5;
        ipc_log_string(v6, "ipa %s:%d CB# %d is set to s1 bypass\n", "ipa3_smmu_map_peer_buff", 423, a5);
        v5 = ipa3_ctx;
        a5 = v7;
      }
      v8 = *(_QWORD *)(v5 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d CB# %d is set to s1 bypass\n", "ipa3_smmu_map_peer_buff", 423, a5);
    }
    v9 = 0;
    goto LABEL_68;
  }
  smmu_domain_by_type = (const void *)ipa3_get_smmu_domain_by_type(a5);
  if ( !smmu_domain_by_type )
  {
    printk(&unk_3DDF55, "ipa3_smmu_map_peer_buff");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_peer_buff", 429);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(v41, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_peer_buff", 429);
    }
    goto LABEL_67;
  }
  v15 = smmu_domain_by_type;
  v50 = a1;
  v49 = a3;
  if ( (a3 & 1) != 0 )
  {
    if ( a4 )
    {
      if ( *(_DWORD *)(a4 + 8) )
      {
        v16 = *(_QWORD *)a4;
        v17 = 0;
        v18 = a1 & 0xFFFFFFFFFFFFF000LL;
        while ( 1 )
        {
          v19 = (*(_DWORD *)(v16 + 8) + *(_DWORD *)(v16 + 12) + 4095) & 0xFFFFF000;
          v51[0] = ((*(_QWORD *)v16 & 0x3FFFFFFFFFFFFFCLL) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL)
                                                           + 0x140000000LL) << 6;
          if ( (unsigned int)ipa3_iommu_map(v15, v18, v51[0], v19, 3u) )
            break;
          v18 += v19;
          ++v17;
          v16 = sg_next(v16);
          if ( v17 >= *(_DWORD *)(a4 + 8) )
            goto LABEL_35;
        }
        printk(&unk_3EE93F, "ipa3_smmu_map_peer_buff");
        v42 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v43 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v43 )
          {
            ipc_log_string(v43, "ipa %s:%d Fail to map pa=%pa, va 0x%lX\n", "ipa3_smmu_map_peer_buff", 450, v51, v18);
            v42 = ipa3_ctx;
          }
          v44 = *(_QWORD *)(v42 + 34160);
          if ( v44 )
            ipc_log_string(v44, "ipa %s:%d Fail to map pa=%pa, va 0x%lX\n", "ipa3_smmu_map_peer_buff", 450, v51, v18);
        }
        goto LABEL_67;
      }
      goto LABEL_35;
    }
    if ( (unsigned int)ipa3_iommu_map(
                         smmu_domain_by_type,
                         a1 & 0xFFFFFFFFFFFFF000LL,
                         a1 & 0xFFFFFFFFFFFFF000LL,
                         ((a1 & 0xFFF) + a2 + 4095) & 0x3FFFFF000LL,
                         3u) )
    {
      printk(&unk_3C683A, "ipa3_smmu_map_peer_buff");
      v28 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v29 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_peer_buff", 465, a1);
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
          ipc_log_string(v30, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_peer_buff", 465, a1);
      }
LABEL_67:
      v9 = -22;
      goto LABEL_68;
    }
  }
  else if ( a4 )
  {
    if ( *(_DWORD *)(a4 + 8) )
    {
      v20 = *(_QWORD *)a4;
      v9 = 0;
      v21 = 0;
      v22 = a1 & 0xFFFFFFFFFFFFF000LL;
      do
      {
        v23 = (*(_DWORD *)(v20 + 8) + *(_DWORD *)(v20 + 12) + 4095) & 0xFFFFF000;
        v51[0] = ((*(_QWORD *)v20 & 0x3FFFFFFFFFFFFFCLL) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
        v24 = iommu_unmap(v15, v22, v23);
        if ( v23 != v24 )
        {
          printk(&unk_3B1C42, "ipa3_smmu_map_peer_buff");
          v25 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v26 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v26 )
            {
              ipc_log_string(
                v26,
                "ipa %s:%d Fail to unmap pa=%pa, va 0x%lX, res %d\n",
                "ipa3_smmu_map_peer_buff",
                481,
                v51,
                v22,
                v24);
              v25 = ipa3_ctx;
            }
            v27 = *(_QWORD *)(v25 + 34160);
            if ( v27 )
              ipc_log_string(
                v27,
                "ipa %s:%d Fail to unmap pa=%pa, va 0x%lX, res %d\n",
                "ipa3_smmu_map_peer_buff",
                481,
                v51,
                v22,
                v24);
          }
          v9 = -22;
        }
        v22 += v23;
        ++v21;
        v20 = sg_next(v20);
      }
      while ( v21 < *(_DWORD *)(a4 + 8) );
      goto LABEL_36;
    }
  }
  else if ( (((a1 & 0xFFF) + a2 + 4095) & 0x3FFFFF000LL) != (int)iommu_unmap(
                                                                   smmu_domain_by_type,
                                                                   a1 & 0xFFFFFFFFFFFFF000LL,
                                                                   ((a1 & 0xFFF) + a2 + 4095) & 0x3FFFFF000LL) )
  {
    printk(&unk_3D52EA, "ipa3_smmu_map_peer_buff");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d Fail to unmap 0x%llx\n", "ipa3_smmu_map_peer_buff", 496, a1);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
        ipc_log_string(v47, "ipa %s:%d Fail to unmap 0x%llx\n", "ipa3_smmu_map_peer_buff", 496, a1);
    }
    goto LABEL_67;
  }
LABEL_35:
  v9 = 0;
LABEL_36:
  v31 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      if ( (v49 & 1) != 0 )
        v33 = "map";
      else
        v33 = "unmap";
      ipc_log_string(v32, "ipa %s:%d Peer buff %s 0x%llx\n", "ipa3_smmu_map_peer_buff", 501, v33, v50);
      v31 = ipa3_ctx;
    }
    v34 = *(_QWORD *)(v31 + 34160);
    if ( v34 )
    {
      if ( (v49 & 1) != 0 )
        v35 = "map";
      else
        v35 = "unmap";
      ipc_log_string(v34, "ipa %s:%d Peer buff %s 0x%llx\n", "ipa3_smmu_map_peer_buff", 501, v35, v50);
    }
  }
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return v9;
}
