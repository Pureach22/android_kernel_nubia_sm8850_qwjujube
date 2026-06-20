__int64 __fastcall ipa3_set_nat_conn_track_exc_rt_tbl(unsigned int a1, unsigned int a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  _DWORD *v8; // x0
  __int64 v9; // x3
  _DWORD *v10; // x20
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0

  if ( a2 <= 1 && *(_DWORD *)(ipa3_ctx + 32240) > 0x17u )
  {
    mutex_lock(ipa3_ctx + 29472);
    v8 = (_DWORD *)ipa3_id_find(a1);
    if ( v8 )
    {
      if ( v8[4] == 1468208645 && v8[20] )
      {
        v9 = (unsigned int)v8[18];
        v10 = v8;
        if ( a2 )
          v11 = 165;
        else
          v11 = 164;
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(v11, 0, 0, v9);
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(
              v13,
              "ipa %s:%d Set exception routing table for %d, ID: %d",
              "ipa3_set_nat_conn_track_exc_rt_tbl",
              2613,
              a2,
              v10[18]);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(
              v14,
              "ipa %s:%d Set exception routing table for %d, ID: %d",
              "ipa3_set_nat_conn_track_exc_rt_tbl",
              2613,
              a2,
              v10[18]);
        }
        v15 = 0;
        goto LABEL_34;
      }
      if ( (unsigned int)__ratelimit(&ipa3_set_nat_conn_track_exc_rt_tbl__rs_146, "ipa3_set_nat_conn_track_exc_rt_tbl") )
      {
        printk(&unk_3EC4EF, "ipa3_set_nat_conn_track_exc_rt_tbl");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_23;
      }
      else
      {
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_23:
          v17 = *(_QWORD *)(v16 + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d bad params\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2601);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d bad params\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2601);
        }
      }
LABEL_33:
      v15 = -22;
LABEL_34:
      mutex_unlock(ipa3_ctx + 29472);
      return v15;
    }
    if ( (unsigned int)__ratelimit(&ipa3_set_nat_conn_track_exc_rt_tbl__rs_145, "ipa3_set_nat_conn_track_exc_rt_tbl") )
    {
      printk(&unk_3DE445, "ipa3_set_nat_conn_track_exc_rt_tbl");
      v19 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_33;
    }
    else
    {
      v19 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_33;
    }
    v20 = *(_QWORD *)(v19 + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d lookup failed\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2595);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
      ipc_log_string(v21, "ipa %s:%d lookup failed\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2595);
    goto LABEL_33;
  }
  if ( (unsigned int)__ratelimit(&ipa3_set_nat_conn_track_exc_rt_tbl__rs, "ipa3_set_nat_conn_track_exc_rt_tbl") )
  {
    printk(&unk_3ECAF0, "ipa3_set_nat_conn_track_exc_rt_tbl");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_5:
      v4 = *(_QWORD *)(v3 + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d bad params: %d,\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2588, a2);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d bad params: %d,\n", "ipa3_set_nat_conn_track_exc_rt_tbl", 2588, a2);
        return 4294967274LL;
      }
    }
  }
  else
  {
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_5;
  }
  return 4294967274LL;
}
