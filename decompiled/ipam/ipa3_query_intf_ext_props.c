__int64 __fastcall ipa3_query_intf_ext_props(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x23
  __int64 v4; // x21
  unsigned int v5; // w3
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0

  if ( a1 )
  {
    mutex_lock(ipa3_ctx + 29472);
    v2 = ipa3_ctx;
    v3 = ipa3_ctx + 32056;
    v4 = ipa3_ctx + 32056;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == v3 )
      {
        v6 = -22;
        goto LABEL_15;
      }
    }
    while ( strcmp((const char *)(v4 - 32), (const char *)a1) );
    v5 = *(_DWORD *)(v4 + 24);
    if ( v5 == *(_DWORD *)(a1 + 32) )
    {
      memcpy((void *)(a1 + 36), *(const void **)(v4 + 48), 216LL * v5);
      v2 = ipa3_ctx;
      v6 = 0;
LABEL_15:
      mutex_unlock(v2 + 29472);
      return v6;
    }
    printk(&unk_3CFD5D, "ipa3_query_intf_ext_props");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d invalid entry number(%u %u)\n",
          "ipa3_query_intf_ext_props",
          367,
          *(_DWORD *)(v4 + 24),
          *(_DWORD *)(a1 + 32));
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d invalid entry number(%u %u)\n",
          "ipa3_query_intf_ext_props",
          367,
          *(_DWORD *)(v4 + 24),
          *(_DWORD *)(a1 + 32));
        v11 = ipa3_ctx;
      }
    }
    mutex_unlock(v11 + 29472);
    return (unsigned int)-22;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_query_intf_ext_props__rs, "ipa3_query_intf_ext_props") )
      printk(&unk_3B82EA, "ipa3_query_intf_ext_props");
    v7 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-22;
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d invalid param ext=%pK\n", "ipa3_query_intf_ext_props", 356, nullptr);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d invalid param ext=%pK\n", "ipa3_query_intf_ext_props", 356, nullptr);
      return (unsigned int)-22;
    }
    else
    {
      return (unsigned int)-22;
    }
  }
}
