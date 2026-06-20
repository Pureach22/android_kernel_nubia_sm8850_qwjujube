__int64 __fastcall ipa3_get_rt_tbl(unsigned int *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v6; // x0
  _DWORD *v7; // x0
  int v8; // w8
  unsigned int v9; // w9
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0

  if ( a1 && *a1 < 2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    v6 = *a1;
    *((_BYTE *)a1 + 35) = 0;
    v7 = (_DWORD *)((__int64 (__fastcall *)(__int64, unsigned int *))_ipa3_find_rt_tbl)(v6, a1 + 1);
    if ( v7 && v7[4] == 1468208645 )
    {
      v8 = v7[20];
      if ( v8 != -1 )
      {
        v9 = v7[52];
        v7[20] = v8 + 1;
        v10 = ipa3_ctx;
        a1[9] = v9;
        v11 = *a1;
        v12 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v10 + 34176) + 120LL);
        if ( *((_DWORD *)v12 - 1) != 1856640366 )
          __break(0x8228u);
        if ( !v12(v11) )
          goto LABEL_23;
        if ( (unsigned int)__ratelimit(&ipa3_get_rt_tbl__rs_102, "ipa3_get_rt_tbl") )
        {
          printk(&unk_3DBD20, "ipa3_get_rt_tbl");
          v13 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_19;
        }
        else
        {
          v13 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_19:
            v14 = *(_QWORD *)(v13 + 34152);
            if ( v14 )
            {
              ipc_log_string(v14, "ipa %s:%d fail to commit RT tbl\n", "ipa3_get_rt_tbl", 2125);
              v13 = ipa3_ctx;
            }
            v15 = *(_QWORD *)(v13 + 34160);
            if ( v15 )
              ipc_log_string(v15, "ipa %s:%d fail to commit RT tbl\n", "ipa3_get_rt_tbl", 2125);
          }
        }
LABEL_23:
        v16 = 0;
LABEL_31:
        mutex_unlock(ipa3_ctx + 29472);
        return v16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_get_rt_tbl__rs_99, "ipa3_get_rt_tbl") )
      {
        printk(&unk_3D3575, "ipa3_get_rt_tbl");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_26;
      }
      else
      {
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_26:
          v18 = *(_QWORD *)(v17 + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d fail: ref count crossed limit\n", "ipa3_get_rt_tbl", 2117);
            v17 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v17 + 34160);
          if ( v19 )
            ipc_log_string(v19, "ipa %s:%d fail: ref count crossed limit\n", "ipa3_get_rt_tbl", 2117);
        }
      }
    }
    v16 = -14;
    goto LABEL_31;
  }
  if ( (unsigned int)__ratelimit(&ipa3_get_rt_tbl__rs, "ipa3_get_rt_tbl") )
    printk(&unk_3C3EF1, "ipa3_get_rt_tbl");
  v2 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 4294967274LL;
  v3 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v3 )
  {
    ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_get_rt_tbl", 2109);
    v2 = ipa3_ctx;
  }
  v4 = *(_QWORD *)(v2 + 34160);
  if ( !v4 )
    return 4294967274LL;
  ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_get_rt_tbl", 2109);
  return 4294967274LL;
}
