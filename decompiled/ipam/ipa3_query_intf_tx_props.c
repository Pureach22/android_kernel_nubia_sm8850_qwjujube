__int64 __fastcall ipa3_query_intf_tx_props(__int64 a1)
{
  size_t v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x21
  unsigned int v13; // w3
  unsigned int v14; // w19
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  if ( a1 )
  {
    *(_BYTE *)(a1 + 31) = 0;
    v2 = strnlen((const char *)a1, 0x20u);
    if ( v2 >= 0x21 )
    {
      _fortify_panic(2, 32, v2 + 1);
      JUMPOUT(0x4A97174);
    }
    if ( v2 == 32 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_query_intf_tx_props__rs_32, "ipa3_query_intf_tx_props") )
        printk(&unk_3C41CD, "ipa3_query_intf_tx_props");
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(
            v4,
            "ipa %s:%d Interface name too long. (%s)\n",
            "ipa3_query_intf_tx_props",
            266,
            (const char *)a1);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
          ipc_log_string(
            v5,
            "ipa %s:%d Interface name too long. (%s)\n",
            "ipa3_query_intf_tx_props",
            266,
            (const char *)a1);
      }
    }
    else
    {
      mutex_lock(ipa3_ctx + 29472);
      v10 = ipa3_ctx;
      v11 = ipa3_ctx + 32056;
      v12 = ipa3_ctx + 32056;
      do
      {
        v12 = *(_QWORD *)v12;
        if ( v12 == v11 )
        {
          v14 = -22;
          goto LABEL_25;
        }
      }
      while ( strcmp((const char *)(v12 - 32), (const char *)a1) );
      v13 = *(_DWORD *)(v12 + 16);
      if ( v13 == *(_DWORD *)(a1 + 32) )
      {
        memcpy((void *)(a1 + 36), *(const void **)(v12 + 32), 200LL * v13);
        v10 = ipa3_ctx;
        v14 = 0;
LABEL_25:
        mutex_unlock(v10 + 29472);
        return v14;
      }
      printk(&unk_3CFD5D, "ipa3_query_intf_tx_props");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d invalid entry number(%u %u)\n",
            "ipa3_query_intf_tx_props",
            277,
            *(_DWORD *)(v12 + 16),
            *(_DWORD *)(a1 + 32));
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
        {
          ipc_log_string(
            v17,
            "ipa %s:%d invalid entry number(%u %u)\n",
            "ipa3_query_intf_tx_props",
            277,
            *(_DWORD *)(v12 + 16),
            *(_DWORD *)(a1 + 32));
          v15 = ipa3_ctx;
        }
      }
      mutex_unlock(v15 + 29472);
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_query_intf_tx_props__rs, "ipa3_query_intf_tx_props") )
      printk(&unk_3B25BF, "ipa3_query_intf_tx_props");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d null args: tx\n", "ipa3_query_intf_tx_props", 260);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d null args: tx\n", "ipa3_query_intf_tx_props", 260);
    }
  }
  return 4294967274LL;
}
