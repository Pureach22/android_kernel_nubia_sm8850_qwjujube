__int64 __fastcall ipa3_wigig_smmu_map_reg(unsigned __int64 a1, char a2, unsigned int a3)
{
  __int64 v5; // x8
  __int64 v6; // x0
  const char *v7; // x5
  __int64 v8; // x0
  const char *v9; // x5
  _QWORD *v10; // x21
  _UNKNOWN **v11; // x9
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  char v15; // w8
  __int64 v16; // x9
  unsigned __int8 v17; // w8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w22
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v24; // w0
  __int64 v25; // x0
  void *v26; // x2
  unsigned __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v32; // x9
  unsigned __int8 v33; // w8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int v39; // w0
  void **v40; // x8
  _QWORD *v41; // x9
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  unsigned __int64 v51[2]; // [xsp+0h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  v51[0] = a1;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      if ( (a2 & 1) != 0 )
        v7 = "map";
      else
        v7 = "unmap";
      ipc_log_string(v6, "ipa %s:%d addr %pa, %s\n", "ipa3_wigig_smmu_map_reg", 250, v51, v7);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
    {
      if ( (a2 & 1) != 0 )
        v9 = "map";
      else
        v9 = "unmap";
      ipc_log_string(v8, "ipa %s:%d addr %pa, %s\n", "ipa3_wigig_smmu_map_reg", 250, v51, v9);
    }
  }
  mutex_lock(&smmu_lock);
  v10 = smmu_reg_addr_list;
  if ( smmu_reg_addr_list == (_UNKNOWN *)&smmu_reg_addr_list )
  {
LABEL_28:
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(
          v22,
          "ipa %s:%d new page found %pa, map and add to list CB %d\n",
          "ipa3_wigig_smmu_map_reg",
          280,
          v51,
          a3);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(
          v23,
          "ipa %s:%d new page found %pa, map and add to list CB %d\n",
          "ipa3_wigig_smmu_map_reg",
          280,
          v51,
          a3);
    }
    v24 = ipa3_smmu_map_peer_reg(v51[0], a2 & 1, a3);
    if ( v24 )
    {
      v20 = v24;
      printk(&unk_3E1CA6, "ipa3_wigig_smmu_map_reg");
      v42 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d failed to map %pa\n", "ipa3_wigig_smmu_map_reg", 283, v51);
          v42 = ipa3_ctx;
        }
        v44 = *(_QWORD *)(v42 + 34160);
        if ( v44 )
          ipc_log_string(v44, "ipa %s:%d failed to map %pa\n", "ipa3_wigig_smmu_map_reg", 283, v51);
      }
    }
    else
    {
      v25 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
      if ( v25 )
      {
        *(_QWORD *)v25 = v25;
        *(_QWORD *)(v25 + 8) = v25;
        v26 = smmu_reg_addr_list;
        v27 = v51[0];
        *(_DWORD *)(v25 + 24) = a3;
        *(_QWORD *)(v25 + 16) = v27;
        *(_BYTE *)(v25 + 28) = 1;
        if ( v26 == (void *)v25 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)v26) != &smmu_reg_addr_list )
        {
          _list_add_valid_or_report(v25, &smmu_reg_addr_list);
          v20 = 0;
        }
        else
        {
          v20 = 0;
          *(_QWORD *)((char *)&unk_8 + (_QWORD)v26) = v25;
          *(_QWORD *)v25 = v26;
          *(_QWORD *)(v25 + 8) = &smmu_reg_addr_list;
          smmu_reg_addr_list = (_UNKNOWN *)v25;
        }
      }
      else
      {
        printk(&unk_3CA9CA, "ipa3_wigig_smmu_map_reg");
        v48 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v49 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v49 )
          {
            ipc_log_string(v49, "ipa %s:%d couldn't allocate for %pa\n", "ipa3_wigig_smmu_map_reg", 289, v51);
            v48 = ipa3_ctx;
          }
          v50 = *(_QWORD *)(v48 + 34160);
          if ( v50 )
            ipc_log_string(v50, "ipa %s:%d couldn't allocate for %pa\n", "ipa3_wigig_smmu_map_reg", 289, v51);
        }
        ipa3_smmu_map_peer_reg(v51[0], (a2 & 1) == 0, a3);
        v20 = -12;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v11 = (_UNKNOWN **)*v10;
      if ( v10[2] == v51[0] && *((_DWORD *)v10 + 6) == a3 )
        break;
      v10 = (_QWORD *)*v10;
      if ( v11 == &smmu_reg_addr_list )
        goto LABEL_28;
    }
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d cb %d, page %pa already mapped, ", "ipa3_wigig_smmu_map_reg", 256, a3, v51);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d cb %d, page %pa already mapped, ", "ipa3_wigig_smmu_map_reg", 256, a3, v51);
    }
    v15 = *((_BYTE *)v10 + 28);
    if ( (a2 & 1) != 0 )
    {
      v16 = ipa3_ctx;
      v17 = v15 + 1;
      *((_BYTE *)v10 + 28) = v17;
      if ( v16 )
      {
        v18 = *(_QWORD *)(v16 + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d inc to %d\n", "ipa3_wigig_smmu_map_reg", 259, v17);
          v16 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v16 + 34160);
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d inc to %d\n", "ipa3_wigig_smmu_map_reg", 259, *((unsigned __int8 *)v10 + 28));
          v20 = 0;
          goto LABEL_38;
        }
      }
      goto LABEL_60;
    }
    v32 = ipa3_ctx;
    v33 = v15 - 1;
    *((_BYTE *)v10 + 28) = v33;
    if ( v32 )
    {
      v34 = *(_QWORD *)(v32 + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d dec to %d\n", "ipa3_wigig_smmu_map_reg", 262, v33);
        v32 = ipa3_ctx;
        v33 = *((_BYTE *)v10 + 28);
      }
      v35 = *(_QWORD *)(v32 + 34160);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d dec to %d\n", "ipa3_wigig_smmu_map_reg", 262, v33);
        v33 = *((_BYTE *)v10 + 28);
      }
    }
    if ( v33 )
    {
LABEL_60:
      v20 = 0;
      goto LABEL_38;
    }
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d unmap and delete\n", "ipa3_wigig_smmu_map_reg", 264);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d unmap and delete\n", "ipa3_wigig_smmu_map_reg", 264);
    }
    v39 = ipa3_smmu_map_peer_reg(v51[0], 0, a3);
    if ( !v39 )
    {
      v40 = (void **)v10[1];
      if ( *v40 == v10 && (v41 = (_QWORD *)*v10, *(_QWORD **)(*v10 + 8LL) == v10) )
      {
        v41[1] = v40;
        *v40 = v41;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      kfree(v10);
      goto LABEL_60;
    }
    v20 = v39;
    printk(&unk_3B0976, "ipa3_wigig_smmu_map_reg");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d failed to unmap %pa\n", "ipa3_wigig_smmu_map_reg", 269, v51);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
        ipc_log_string(v47, "ipa %s:%d failed to unmap %pa\n", "ipa3_wigig_smmu_map_reg", 269, v51);
    }
  }
LABEL_38:
  mutex_unlock(&smmu_lock);
  v28 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_reg", 302);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( v30 )
      ipc_log_string(v30, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_reg", 302);
  }
  _ReadStatusReg(SP_EL0);
  return v20;
}
