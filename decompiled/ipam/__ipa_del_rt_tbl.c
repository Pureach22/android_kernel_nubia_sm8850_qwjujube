__int64 __fastcall _ipa_del_rt_tbl(__int64 *a1)
{
  unsigned int v1; // w19
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 *v5; // x8
  unsigned int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  char v14; // w11
  __int64 v15; // x21
  __int64 **v16; // x11
  __int64 v17; // x9
  __int64 *v18; // x10
  __int64 *v19; // x2
  unsigned __int64 v20; // x11
  __int64 v21; // x9
  __int64 v22; // x9
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 **v25; // x9
  __int64 *v26; // x10
  unsigned __int64 v27; // x12
  _QWORD *v28; // x9
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int64 v37; // x11
  unsigned __int64 v40; // x11

  if ( !a1 || *((_DWORD *)a1 + 4) != 1468208645 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_del_rt_tbl__rs, "__ipa_del_rt_tbl") )
    {
      printk(&unk_3EC4EF, "__ipa_del_rt_tbl");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_9;
    }
    else
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_9:
        v8 = *(_QWORD *)(v7 + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d bad params\n", "__ipa_del_rt_tbl", 932);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d bad params\n", "__ipa_del_rt_tbl", 932);
      }
    }
    return 4294967274LL;
  }
  v1 = *((_DWORD *)a1 + 52);
  if ( !ipa3_id_find(v1) )
  {
    if ( (unsigned int)__ratelimit(&_ipa_del_rt_tbl__rs_243, "__ipa_del_rt_tbl") )
    {
      printk(&unk_3DE445, "__ipa_del_rt_tbl");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 0xFFFFFFFFLL;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 0xFFFFFFFFLL;
    }
    v12 = *(_QWORD *)(v11 + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d lookup failed\n", "__ipa_del_rt_tbl", 937);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d lookup failed\n", "__ipa_del_rt_tbl", 937);
    return 0xFFFFFFFFLL;
  }
  v3 = ipa3_ctx;
  v4 = a1[11];
  v5 = a1;
  if ( v4 != ipa3_ctx + 29184 )
  {
    if ( v4 == ipa3_ctx + 29232 )
    {
      v6 = 1;
      goto LABEL_22;
    }
    return 0xFFFFFFFFLL;
  }
  v6 = 0;
LABEL_22:
  v14 = *((_BYTE *)a1 + 96);
  v15 = v6;
  a1[27] = 0;
  if ( (v14 & 1) != 0 || *((_BYTE *)a1 + 97) == 1 )
  {
    v16 = (__int64 **)a1[1];
    v17 = v3 + 48LL * v6 + 29280;
    if ( *v16 == a1 && (v18 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v18[1] = (__int64)v16;
      *v16 = v18;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
      v5 = a1;
    }
    v19 = *(__int64 **)v17;
    if ( *(_QWORD *)(*(_QWORD *)v17 + 8LL) != v17 || (__int64 *)v17 == v5 || v19 == v5 )
    {
      _list_add_valid_or_report(a1, v17);
      v5 = a1;
    }
    else
    {
      v19[1] = (__int64)v5;
      *v5 = (__int64)v19;
      v5[1] = v17;
      *(_QWORD *)v17 = v5;
    }
    v20 = *((unsigned int *)v5 + 18);
    v21 = 1LL << v20;
    _X10 = (unsigned __int64 *)(ipa3_ctx + 8 * v15 + 29456 + 8 * (v20 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v37 = __ldxr(_X10);
    while ( __stxr(v37 & ~v21, _X10) );
    v22 = ipa3_ctx;
    --*(_DWORD *)(v5[11] + 16);
    if ( v22 )
    {
      v23 = *(_QWORD *)(v22 + 34152);
      if ( v23 )
      {
        ipc_log_string(
          v23,
          "ipa %s:%d del sys rt tbl_idx=%d tbl_cnt=%d ip=%d\n",
          "__ipa_del_rt_tbl",
          959,
          *((_DWORD *)v5 + 18),
          *(_DWORD *)(v5[11] + 16),
          v15);
        v22 = ipa3_ctx;
        v5 = a1;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(
          v24,
          "ipa %s:%d del sys rt tbl_idx=%d tbl_cnt=%d ip=%d\n",
          "__ipa_del_rt_tbl",
          959,
          *((_DWORD *)v5 + 18),
          *(_DWORD *)(v5[11] + 16),
          v15);
    }
  }
  else
  {
    v25 = (__int64 **)a1[1];
    if ( *v25 == a1 && (v26 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v26[1] = (__int64)v25;
      *v25 = v26;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
      v5 = a1;
    }
    v27 = *((unsigned int *)v5 + 18);
    *v5 = 0xDEAD000000000100LL;
    v5[1] = 0xDEAD000000000122LL;
    _X10 = (unsigned __int64 *)(ipa3_ctx + 8 * v15 + 29456 + 8 * (v27 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v40 = __ldxr(_X10);
    while ( __stxr(v40 & ~(1LL << v27), _X10) );
    v28 = (_QWORD *)ipa3_ctx;
    --*(_DWORD *)(v5[11] + 16);
    if ( v28 )
    {
      v29 = v28[4269];
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d del rt tbl_idx=%d tbl_cnt=%d ip=%d\n",
          "__ipa_del_rt_tbl",
          965,
          *((_DWORD *)v5 + 18),
          *(_DWORD *)(v5[11] + 16),
          v15);
        v28 = (_QWORD *)ipa3_ctx;
      }
      v30 = v28[4270];
      if ( v30 )
      {
        ipc_log_string(
          v30,
          "ipa %s:%d del rt tbl_idx=%d tbl_cnt=%d ip=%d\n",
          "__ipa_del_rt_tbl",
          965,
          *((_DWORD *)a1 + 18),
          *(_DWORD *)(a1[11] + 16),
          v15);
        v28 = (_QWORD *)ipa3_ctx;
      }
    }
    kmem_cache_free(v28[3679], a1);
  }
  ipa3_id_remove(v1);
  return 0;
}
