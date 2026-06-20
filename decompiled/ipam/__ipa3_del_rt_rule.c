__int64 __fastcall _ipa3_del_rt_rule(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x19
  __int64 v3; // x22
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  _QWORD *v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  unsigned int v32; // w20
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0

  v1 = ipa3_id_find(a1);
  if ( !v1 )
  {
    if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs, "__ipa3_del_rt_rule") )
      printk(&unk_3DE445, "__ipa3_del_rt_rule");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d lookup failed\n", "__ipa3_del_rt_rule", 1784);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d lookup failed\n", "__ipa3_del_rt_rule", 1784);
    }
    return 4294967274LL;
  }
  v2 = v1;
  if ( *(_DWORD *)(v1 + 16) != 1468208644 )
  {
    if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs_63, "__ipa3_del_rt_rule") )
      printk(&unk_3EC4EF, "__ipa3_del_rt_rule");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d bad params\n", "__ipa3_del_rt_rule", 1789);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d bad params\n", "__ipa3_del_rt_rule", 1789);
    }
    return 4294967274LL;
  }
  if ( (ipa3_check_idr_if_freed(v1) & 1) == 0 )
  {
    v3 = *(_QWORD *)(v2 + 200);
    if ( !strcmp((const char *)(v3 + 40), "ipa_dflt_rt") )
    {
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d Deleting rule from default rt table idx=%u\n",
            "__ipa3_del_rt_rule",
            1796,
            *(_DWORD *)(v3 + 72));
          v4 = ipa3_ctx;
          v3 = *(_QWORD *)(v2 + 200);
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d Deleting rule from default rt table idx=%u\n",
            "__ipa3_del_rt_rule",
            1796,
            *(_DWORD *)(v3 + 72));
          v3 = *(_QWORD *)(v2 + 200);
        }
      }
      if ( *(_DWORD *)(v3 + 76) == 1 && (*(_BYTE *)(ipa3_ctx + 45220) & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs_67, "__ipa3_del_rt_rule") )
        {
          printk(&unk_3AD553, "__ipa3_del_rt_rule");
          v36 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_78;
        }
        else
        {
          v36 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_78:
            v37 = *(_QWORD *)(v36 + 34152);
            if ( v37 )
            {
              ipc_log_string(v37, "ipa %s:%d Default tbl last rule cannot be deleted\n", "__ipa3_del_rt_rule", 1798);
              v36 = ipa3_ctx;
            }
            v38 = *(_QWORD *)(v36 + 34160);
            if ( v38 )
              ipc_log_string(v38, "ipa %s:%d Default tbl last rule cannot be deleted\n", "__ipa3_del_rt_rule", 1798);
          }
        }
        return 4294967274LL;
      }
    }
  }
  if ( *(_QWORD *)(v2 + 208) )
  {
    v7 = ipa3_id_find(*(unsigned int *)(v2 + 24));
    if ( !v7 || *(_DWORD *)(v7 + 16) != 1468208647 )
    {
      if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs_70, "__ipa3_del_rt_rule") )
        printk(&unk_3D352B, "__ipa3_del_rt_rule");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d Header entry already deleted\n", "__ipa3_del_rt_rule", 1810);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d Header entry already deleted\n", "__ipa3_del_rt_rule", 1810);
      }
      *(_QWORD *)(v2 + 208) = 0;
      goto LABEL_51;
    }
  }
  else if ( *(_QWORD *)(v2 + 216) )
  {
    v18 = ipa3_id_find(*(unsigned int *)(v2 + 28));
    if ( !v18 || *(_DWORD *)(v18 + 16) != 1468208648 )
    {
      if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs_73, "__ipa3_del_rt_rule") )
        printk(&unk_3DEBEF, "__ipa3_del_rt_rule");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v20 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d Proc header entry already deleted\n", "__ipa3_del_rt_rule", 1817);
          v19 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v19 + 34160);
        if ( v21 )
          ipc_log_string(v21, "ipa %s:%d Proc header entry already deleted\n", "__ipa3_del_rt_rule", 1817);
      }
      *(_QWORD *)(v2 + 216) = 0;
    }
  }
  v22 = *(_QWORD *)(v2 + 208);
  if ( v22 && (ipa3_check_idr_if_freed(v22) & 1) == 0 )
  {
    _ipa3_release_hdr(*(unsigned int *)(*(_QWORD *)(v2 + 208) + 340LL));
    goto LABEL_55;
  }
LABEL_51:
  v23 = *(_QWORD *)(v2 + 216);
  if ( v23 && (ipa3_check_idr_if_freed(v23) & 1) == 0 )
    _ipa3_release_hdr_proc_ctx(*(unsigned int *)(*(_QWORD *)(v2 + 216) + 76LL));
LABEL_55:
  v24 = *(_QWORD **)(v2 + 8);
  if ( *v24 == v2 && (v25 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v25 + 8) = v24;
    *v24 = v25;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
  }
  v26 = *(_QWORD *)(v2 + 200);
  *(_QWORD *)v2 = 0xDEAD000000000100LL;
  *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
  v27 = ipa3_ctx;
  --*(_DWORD *)(v26 + 76);
  if ( v27 )
  {
    v28 = *(_QWORD *)(v27 + 34152);
    if ( v28 )
    {
      ipc_log_string(
        v28,
        "ipa %s:%d del rt rule tbl_idx=%d rule_cnt=%d rule_id=%d\n ref_cnt=%u",
        "__ipa3_del_rt_rule",
        1832,
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 72LL),
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 76LL),
        *(unsigned __int16 *)(v2 + 234),
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 80LL));
      v27 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v27 + 34160);
    if ( v29 )
      ipc_log_string(
        v29,
        "ipa %s:%d del rt rule tbl_idx=%d rule_cnt=%d rule_id=%d\n ref_cnt=%u",
        "__ipa3_del_rt_rule",
        1832,
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 72LL),
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 76LL),
        *(unsigned __int16 *)(v2 + 234),
        *(_DWORD *)(*(_QWORD *)(v2 + 200) + 80LL));
  }
  if ( !*(_WORD *)(v2 + 236) )
    idr_remove(*(_QWORD *)(*(_QWORD *)(v2 + 200) + 216LL), *(unsigned __int16 *)(v2 + 234));
  v30 = *(_QWORD *)(v2 + 200);
  if ( *(_DWORD *)(v30 + 76) || *(_DWORD *)(v30 + 80) || !(unsigned int)_ipa_del_rt_tbl() )
    goto LABEL_67;
  if ( (unsigned int)__ratelimit(&_ipa3_del_rt_rule__rs_77, "__ipa3_del_rt_rule") )
  {
    printk(&unk_3D3555, "__ipa3_del_rt_rule");
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_71;
  }
  else
  {
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_71:
      v34 = *(_QWORD *)(v33 + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d fail to del RT tbl\n", "__ipa3_del_rt_rule", 1838);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d fail to del RT tbl\n", "__ipa3_del_rt_rule", 1838);
    }
  }
LABEL_67:
  v31 = ipa3_ctx;
  *(_DWORD *)(v2 + 16) = 0;
  v32 = *(_DWORD *)(v2 + 228);
  kmem_cache_free(*(_QWORD *)(v31 + 29384), v2);
  ipa3_id_remove(v32);
  return 0;
}
