__int64 __fastcall ipa3_nat_ipv6ct_create_del_table_cmd(unsigned __int8 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  unsigned int v7; // w21
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x22
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0

  v6 = ipa3_ctx;
  v7 = a2;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d In: tbl_index(%u) base_addr(%u) v4(%u) v6(%u)\n",
        "ipa3_nat_ipv6ct_create_del_table_cmd",
        2222,
        a1,
        a2,
        *(unsigned __int8 *)(a3 + 220),
        *(unsigned __int8 *)(a3 + 221));
      v6 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v6 + 34160);
    if ( v10 )
      ipc_log_string(
        v10,
        "ipa %s:%d In: tbl_index(%u) base_addr(%u) v4(%u) v6(%u)\n",
        "ipa3_nat_ipv6ct_create_del_table_cmd",
        2222,
        a1,
        v7,
        *(unsigned __int8 *)(a3 + 220),
        *(unsigned __int8 *)(a3 + 221));
  }
  if ( a1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_create_del_table_cmd__rs, "ipa3_nat_ipv6ct_create_del_table_cmd") )
    {
      printk(&unk_3F2550, "ipa3_nat_ipv6ct_create_del_table_cmd");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_9;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_9:
        v12 = *(_QWORD *)(v11 + 34152);
        if ( v12 )
        {
          ipc_log_string(
            v12,
            "ipa %s:%d Unsupported table index %d\n",
            "ipa3_nat_ipv6ct_create_del_table_cmd",
            2225,
            a1);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(
            v13,
            "ipa %s:%d Unsupported table index %d\n",
            "ipa3_nat_ipv6ct_create_del_table_cmd",
            2225,
            a1);
      }
    }
    return 0xFFFFFFFFLL;
  }
  v15 = *(_QWORD *)(a3 + 296);
  if ( v15 )
  {
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d using temp memory during %s del\n",
          "ipa3_nat_ipv6ct_create_del_table_cmd",
          2230,
          (const char *)a3);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(
          v18,
          "ipa %s:%d using temp memory during %s del\n",
          "ipa3_nat_ipv6ct_create_del_table_cmd",
          2230,
          (const char *)a3);
    }
    v7 = *(_DWORD *)(*(_QWORD *)(a3 + 296) + 8LL);
  }
  *(_BYTE *)(a4 + 22) = 0;
  *(_QWORD *)a4 = v7;
  *(_QWORD *)(a4 + 8) = v7;
  v19 = ipa3_ctx;
  *(_BYTE *)(a4 + 16) = v15 == 0;
  *(_BYTE *)(a4 + 17) = v15 == 0;
  *(_DWORD *)(a4 + 18) = 0;
  if ( !v19 )
    return 0;
  v20 = *(_QWORD *)(v19 + 34152);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_create_del_table_cmd", 2243);
    v19 = ipa3_ctx;
  }
  result = *(_QWORD *)(v19 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_create_del_table_cmd", 2243);
    return 0;
  }
  return result;
}
