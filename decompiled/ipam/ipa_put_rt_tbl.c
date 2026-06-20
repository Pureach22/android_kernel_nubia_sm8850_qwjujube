__int64 __fastcall ipa_put_rt_tbl(unsigned int a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x10
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
  int v15; // w8
  __int64 v16; // x21
  __int64 v17; // x21
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0

  mutex_lock(ipa3_ctx + 29472);
  v2 = ipa3_id_find(a1);
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&ipa_put_rt_tbl__rs, "ipa_put_rt_tbl") )
    {
      printk(&unk_3DE445, "ipa_put_rt_tbl");
      v10 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_19;
    }
    else
    {
      v10 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_19;
    }
    v11 = *(_QWORD *)(v10 + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d lookup failed\n", "ipa_put_rt_tbl", 2154);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
      ipc_log_string(v12, "ipa %s:%d lookup failed\n", "ipa_put_rt_tbl", 2154);
    goto LABEL_19;
  }
  if ( *(_DWORD *)(v2 + 16) != 1468208645 || (v3 = *(_DWORD *)(v2 + 80)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa_put_rt_tbl__rs_105, "ipa_put_rt_tbl") )
    {
      printk(&unk_3EC4EF, "ipa_put_rt_tbl");
      v7 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_19;
    }
    else
    {
      v7 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_19;
    }
    v8 = *(_QWORD *)(v7 + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d bad params\n", "ipa_put_rt_tbl", 2160);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
      ipc_log_string(v9, "ipa %s:%d bad params\n", "ipa_put_rt_tbl", 2160);
    goto LABEL_19;
  }
  v4 = ipa3_ctx;
  v5 = *(_QWORD *)(v2 + 88);
  if ( v5 == ipa3_ctx + 29184 )
  {
    v6 = 0;
    goto LABEL_22;
  }
  if ( v5 == ipa3_ctx + 29232 )
  {
    v6 = 1;
LABEL_22:
    v15 = v3 - 1;
    *(_DWORD *)(v2 + 80) = v15;
    if ( v15 || *(_DWORD *)(v2 + 76) )
      goto LABEL_24;
    if ( v4 )
    {
      if ( *(_QWORD *)(v4 + 34152) )
      {
        v16 = v2;
        ipc_log_string(
          *(_QWORD *)(v4 + 34152),
          "ipa %s:%d zero ref_cnt, delete rt tbl (idx=%u)\n",
          "ipa_put_rt_tbl",
          2178,
          *(_DWORD *)(v2 + 72));
        v4 = ipa3_ctx;
        v2 = v16;
      }
      if ( *(_QWORD *)(v4 + 34160) )
      {
        v17 = v2;
        ipc_log_string(
          *(_QWORD *)(v4 + 34160),
          "ipa %s:%d zero ref_cnt, delete rt tbl (idx=%u)\n",
          "ipa_put_rt_tbl",
          2178,
          *(_DWORD *)(v2 + 72));
        v2 = v17;
      }
    }
    if ( (unsigned int)_ipa_del_rt_tbl((__int64 *)v2) )
    {
      if ( (unsigned int)__ratelimit(&ipa_put_rt_tbl__rs_107, "ipa_put_rt_tbl") )
      {
        printk(&unk_3D3555, "ipa_put_rt_tbl");
        v18 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_41;
      }
      else
      {
        v18 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_41;
      }
      v19 = *(_QWORD *)(v18 + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d fail to del RT tbl\n", "ipa_put_rt_tbl", 2180);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d fail to del RT tbl\n", "ipa_put_rt_tbl", 2180);
    }
LABEL_41:
    v21 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
    if ( *((_DWORD *)v21 - 1) != 1856640366 )
      __break(0x8228u);
    if ( !v21(v6) )
      goto LABEL_24;
    if ( (unsigned int)__ratelimit(&ipa_put_rt_tbl__rs_108, "ipa_put_rt_tbl") )
    {
      printk(&unk_3DBD20, "ipa_put_rt_tbl");
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_46;
    }
    else
    {
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_46:
        v23 = *(_QWORD *)(v22 + 34152);
        if ( v23 )
        {
          ipc_log_string(v23, "ipa %s:%d fail to commit RT tbl\n", "ipa_put_rt_tbl", 2183);
          v22 = ipa3_ctx;
        }
        v24 = *(_QWORD *)(v22 + 34160);
        if ( v24 )
          ipc_log_string(v24, "ipa %s:%d fail to commit RT tbl\n", "ipa_put_rt_tbl", 2183);
      }
    }
LABEL_24:
    v13 = 0;
    goto LABEL_20;
  }
LABEL_19:
  v13 = -22;
LABEL_20:
  mutex_unlock(ipa3_ctx + 29472);
  return v13;
}
