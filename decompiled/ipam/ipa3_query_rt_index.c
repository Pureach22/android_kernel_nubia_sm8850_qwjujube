__int64 __fastcall ipa3_query_rt_index(unsigned int *a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x9

  if ( *a1 < 2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    v6 = *a1;
    *((_BYTE *)a1 + 35) = 0;
    v7 = ((__int64 (__fastcall *)(__int64, unsigned int *))_ipa3_find_rt_tbl)(v6, a1 + 1);
    if ( v7 )
    {
      v8 = ipa3_ctx;
      a1[9] = *(_DWORD *)(v7 + 72);
      mutex_unlock(v8 + 29472);
      return 0;
    }
    else
    {
      mutex_unlock(ipa3_ctx + 29472);
      return 4294967282LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_query_rt_index__rs, "ipa3_query_rt_index") )
      printk(&unk_3C3EF1, "ipa3_query_rt_index");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d bad param\n", "ipa3_query_rt_index", 821);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_query_rt_index", 821);
    }
    return 4294967274LL;
  }
}
