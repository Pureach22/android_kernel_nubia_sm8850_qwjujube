__int64 __fastcall ipa3_set_aggr_limit(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w23
  unsigned int v11; // w21
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x21
  __int64 v16; // x8
  __int64 v17; // x0
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x0

  if ( *(_BYTE *)(ipa3_ctx + 45386) == 1 )
  {
    result = printk(&unk_3CF945, "ipa3_set_aggr_limit");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d set rx_buff_sz config from netmngr %lu\n",
          "ipa3_set_aggr_limit",
          5795,
          *(unsigned int *)(a2 + 1600));
        v5 = ipa3_ctx;
      }
      result = *(_QWORD *)(v5 + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d set rx_buff_sz config from netmngr %lu\n",
                   "ipa3_set_aggr_limit",
                   5795,
                   *(unsigned int *)(a2 + 1600));
    }
    *(_DWORD *)(a2 + 160) = 2 * *(_DWORD *)(a2 + 1600) - ((*(_DWORD *)(a2 + 1600) + 127) & 0xFFFFFFC0) - 384;
    v7 = a1[26];
  }
  else
  {
    v8 = (a1[26] + 1947) | ((unsigned int)(a1[26] + 1947) >> 1);
    v9 = v8 | (v8 >> 2) | ((v8 | (v8 >> 2)) >> 4);
    v10 = (v9 | (v9 >> 8) | ((v9 | (v9 >> 8)) >> 16)) + 1;
    v11 = v10 >> 1;
    printk(&unk_3D584D, "ipa3_set_aggr_limit");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d get close-by %u\n", "ipa3_set_aggr_limit", 5800, v11);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d get close-by %u\n", "ipa3_set_aggr_limit", 5800, v11);
    }
    v15 = (v10 & 0xFFFFFFFE) - (unsigned __int64)((v11 + 127) & 0xFFFFFFC0) - 384;
    result = printk(&unk_3B4E09, "ipa3_set_aggr_limit");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d set default rx_buff_sz %lu\n", "ipa3_set_aggr_limit", 5802, v15);
        v16 = ipa3_ctx;
      }
      result = *(_QWORD *)(v16 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d set default rx_buff_sz %lu\n", "ipa3_set_aggr_limit", 5802, v15);
    }
    *(_DWORD *)(a2 + 160) = v15;
    v7 = a1[26];
    if ( v7 >= (unsigned int)v15 )
      v7 = v15;
  }
  a1[26] = (v7 - 1500) / 0x3E8;
  *(_BYTE *)(*(_QWORD *)(a2 + 1624) + 352LL) = 0;
  v18 = a1[48];
  if ( v18 == 95 )
  {
LABEL_23:
    a1[29] = 1;
    goto LABEL_24;
  }
  if ( v18 == 35 )
  {
    v19 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
      goto LABEL_25;
    goto LABEL_23;
  }
LABEL_24:
  v19 = ipa3_ctx;
LABEL_25:
  if ( v19 )
  {
    v20 = *(_QWORD *)(v19 + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d set aggr_limit %lu\n", "ipa3_set_aggr_limit", 5817, (unsigned int)a1[26]);
      v19 = ipa3_ctx;
    }
    result = *(_QWORD *)(v19 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d set aggr_limit %lu\n", "ipa3_set_aggr_limit", 5817, (unsigned int)a1[26]);
  }
  return result;
}
