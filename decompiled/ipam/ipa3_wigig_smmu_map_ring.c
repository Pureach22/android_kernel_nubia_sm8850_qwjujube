__int64 __fastcall ipa3_wigig_smmu_map_ring(__int64 a1, unsigned int a2, char a3, __int64 a4)
{
  __int64 v6; // x8
  __int64 v9; // x0
  const char *v10; // x5
  __int64 v11; // x0
  const char *v12; // x5
  _QWORD *v13; // x23
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w0
  __int64 v18; // x0
  void *v19; // x2
  unsigned int v20; // w24
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  _UNKNOWN **v25; // x8
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  char v29; // w8
  __int64 v30; // x9
  unsigned __int8 v31; // w8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x9
  unsigned __int8 v35; // w8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  unsigned int v41; // w0
  void **v42; // x8
  _QWORD *v43; // x9
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0

  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      if ( (a3 & 1) != 0 )
        v10 = "map";
      else
        v10 = "unmap";
      ipc_log_string(v9, "ipa %s:%d iova %llX, %s\n", "ipa3_wigig_smmu_map_ring", 313, a1, v10);
      v6 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v6 + 34160);
    if ( v11 )
    {
      if ( (a3 & 1) != 0 )
        v12 = "map";
      else
        v12 = "unmap";
      ipc_log_string(v11, "ipa %s:%d iova %llX, %s\n", "ipa3_wigig_smmu_map_ring", 313, a1, v12);
    }
  }
  mutex_lock(&smmu_lock);
  v13 = smmu_ring_addr_list;
  if ( smmu_ring_addr_list == (_UNKNOWN *)&smmu_ring_addr_list )
  {
LABEL_13:
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(
          v15,
          "ipa %s:%d new page found 0x%llX, map and add to list\n",
          "ipa3_wigig_smmu_map_ring",
          343,
          a1);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(
          v16,
          "ipa %s:%d new page found 0x%llX, map and add to list\n",
          "ipa3_wigig_smmu_map_ring",
          343,
          a1);
    }
    v17 = ipa3_smmu_map_peer_buff(a1, a2, a3 & 1, a4, 0);
    if ( v17 )
    {
      v20 = v17;
      printk(&unk_3B914F, "ipa3_wigig_smmu_map_ring");
      v44 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v45 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v45 )
        {
          ipc_log_string(v45, "ipa %s:%d failed to map 0x%llX\n", "ipa3_wigig_smmu_map_ring", 346, a1);
          v44 = ipa3_ctx;
        }
        v46 = *(_QWORD *)(v44 + 34160);
        if ( v46 )
          ipc_log_string(v46, "ipa %s:%d failed to map 0x%llX\n", "ipa3_wigig_smmu_map_ring", 346, a1);
      }
    }
    else
    {
      v18 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
      if ( v18 )
      {
        *(_QWORD *)v18 = v18;
        *(_QWORD *)(v18 + 8) = v18;
        v19 = smmu_ring_addr_list;
        *(_QWORD *)(v18 + 16) = a1;
        *(_DWORD *)(v18 + 24) = 0;
        *(_BYTE *)(v18 + 28) = 1;
        if ( v19 == (void *)v18 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)v19) != &smmu_ring_addr_list )
        {
          _list_add_valid_or_report(v18, &smmu_ring_addr_list);
          v20 = 0;
        }
        else
        {
          v20 = 0;
          *(_QWORD *)((char *)&unk_8 + (_QWORD)v19) = v18;
          *(_QWORD *)v18 = v19;
          *(_QWORD *)(v18 + 8) = &smmu_ring_addr_list;
          smmu_ring_addr_list = (_UNKNOWN *)v18;
        }
      }
      else
      {
        printk(&unk_3E7622, "ipa3_wigig_smmu_map_ring");
        v50 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v51 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v51 )
          {
            ipc_log_string(v51, "ipa %s:%d couldn't allocate for 0x%llX\n", "ipa3_wigig_smmu_map_ring", 352, a1);
            v50 = ipa3_ctx;
          }
          v52 = *(_QWORD *)(v50 + 34160);
          if ( v52 )
            ipc_log_string(v52, "ipa %s:%d couldn't allocate for 0x%llX\n", "ipa3_wigig_smmu_map_ring", 352, a1);
        }
        ipa3_smmu_map_peer_buff(a1, a2, (a3 & 1) == 0, a4, 0);
        v20 = -12;
      }
    }
    goto LABEL_23;
  }
  while ( 1 )
  {
    v25 = (_UNKNOWN **)*v13;
    if ( v13[2] == a1 && !*((_DWORD *)v13 + 6) )
      break;
    v13 = (_QWORD *)*v13;
    if ( v25 == &smmu_ring_addr_list )
      goto LABEL_13;
  }
  v26 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v27 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d cb %d, page 0x%llX already mapped, ", "ipa3_wigig_smmu_map_ring", 319, 0, a1);
      v26 = ipa3_ctx;
    }
    v28 = *(_QWORD *)(v26 + 34160);
    if ( v28 )
      ipc_log_string(v28, "ipa %s:%d cb %d, page 0x%llX already mapped, ", "ipa3_wigig_smmu_map_ring", 319, 0, a1);
  }
  v29 = *((_BYTE *)v13 + 28);
  if ( (a3 & 1) != 0 )
  {
    v30 = ipa3_ctx;
    v31 = v29 + 1;
    *((_BYTE *)v13 + 28) = v31;
    if ( v30 )
    {
      v32 = *(_QWORD *)(v30 + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d inc to %d\n", "ipa3_wigig_smmu_map_ring", 322, v31);
        v30 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v30 + 34160);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d inc to %d\n", "ipa3_wigig_smmu_map_ring", 322, *((unsigned __int8 *)v13 + 28));
        v20 = 0;
        goto LABEL_23;
      }
    }
    goto LABEL_59;
  }
  v34 = ipa3_ctx;
  v35 = v29 - 1;
  *((_BYTE *)v13 + 28) = v35;
  if ( v34 )
  {
    v36 = *(_QWORD *)(v34 + 34152);
    if ( v36 )
    {
      ipc_log_string(v36, "ipa %s:%d dec to %d\n", "ipa3_wigig_smmu_map_ring", 325, v35);
      v34 = ipa3_ctx;
      v35 = *((_BYTE *)v13 + 28);
    }
    v37 = *(_QWORD *)(v34 + 34160);
    if ( v37 )
    {
      ipc_log_string(v37, "ipa %s:%d dec to %d\n", "ipa3_wigig_smmu_map_ring", 325, v35);
      v35 = *((_BYTE *)v13 + 28);
    }
  }
  if ( v35 )
  {
LABEL_59:
    v20 = 0;
    goto LABEL_23;
  }
  v38 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d unmap and delete\n", "ipa3_wigig_smmu_map_ring", 327);
      v38 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v38 + 34160);
    if ( v40 )
      ipc_log_string(v40, "ipa %s:%d unmap and delete\n", "ipa3_wigig_smmu_map_ring", 327);
  }
  v41 = ipa3_smmu_map_peer_buff(a1, a2, 0, a4, 0);
  if ( !v41 )
  {
    v42 = (void **)v13[1];
    if ( *v42 == v13 && (v43 = (_QWORD *)*v13, *(_QWORD **)(*v13 + 8LL) == v13) )
    {
      v43[1] = v42;
      *v42 = v43;
    }
    else
    {
      _list_del_entry_valid_or_report(v13);
    }
    *v13 = 0xDEAD000000000100LL;
    v13[1] = 0xDEAD000000000122LL;
    kfree(v13);
    goto LABEL_59;
  }
  v20 = v41;
  printk(&unk_3DC53C, "ipa3_wigig_smmu_map_ring");
  v47 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v48 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v48 )
    {
      ipc_log_string(v48, "ipa %s:%d failed to unmap 0x%llX\n", "ipa3_wigig_smmu_map_ring", 333, a1);
      v47 = ipa3_ctx;
    }
    v49 = *(_QWORD *)(v47 + 34160);
    if ( v49 )
      ipc_log_string(v49, "ipa %s:%d failed to unmap 0x%llX\n", "ipa3_wigig_smmu_map_ring", 333, a1);
  }
LABEL_23:
  mutex_unlock(&smmu_lock);
  v21 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_ring", 365);
      v21 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v21 + 34160);
    if ( v23 )
      ipc_log_string(v23, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_ring", 365);
  }
  return v20;
}
