__int64 __fastcall ipa3_allocate_ipv6ct_table(unsigned __int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int mem; // w0
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d \n", "ipa3_allocate_ipv6ct_table", 844);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d \n", "ipa3_allocate_ipv6ct_table", 844);
      v2 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v2 + 32240) <= 0xDu )
  {
    if ( (unsigned int)__ratelimit(&ipa3_allocate_ipv6ct_table__rs, "ipa3_allocate_ipv6ct_table") )
    {
      printk(&unk_3E1173, "ipa3_allocate_ipv6ct_table");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_9;
    }
    else
    {
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_9:
        v6 = *(_QWORD *)(v5 + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_allocate_ipv6ct_table", 847);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(v7, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_allocate_ipv6ct_table", 847);
      }
    }
    return 0xFFFFFFFFLL;
  }
  mutex_lock(v2 + 30096);
  mem = ipa3_nat_ipv6ct_allocate_mem(ipa3_ctx + 30080, a1, 3u);
  v10 = ipa3_ctx;
  v11 = mem;
  if ( !mem && ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d IPA IPv6CT dev init successfully\n", "ipa3_allocate_ipv6ct_table", 861);
      v10 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v10 + 34160);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d IPA IPv6CT dev init successfully\n", "ipa3_allocate_ipv6ct_table", 861);
      v10 = ipa3_ctx;
    }
  }
  mutex_unlock(v10 + 30096);
  return v11;
}
