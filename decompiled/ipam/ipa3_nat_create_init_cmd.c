__int64 __fastcall ipa3_nat_create_init_cmd(unsigned __int8 *a1, char a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  unsigned int v8; // w22
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w4
  __int64 v16; // x0
  const void *v17; // x19
  __int64 v18; // x0
  __int64 v19; // x0

  v6 = ipa3_ctx;
  v8 = a2 & 1;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d \n", "ipa3_nat_create_init_cmd", 1136);
      v6 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v6 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d \n", "ipa3_nat_create_init_cmd", 1136);
      v6 = ipa3_ctx;
    }
  }
  result = ipa3_nat_ipv6ct_create_init_cmd(
             a4,
             v8,
             a3,
             *a1,
             *((unsigned int *)a1 + 1),
             *((unsigned int *)a1 + 2),
             *((unsigned __int16 *)a1 + 10),
             *((unsigned __int16 *)a1 + 11),
             v6 + 29528);
  *(_BYTE *)(a4 + 40) = v8;
  v12 = ipa3_ctx;
  *(_BYTE *)(a4 + 41) = v8;
  *(_QWORD *)(a4 + 24) = *((unsigned int *)a1 + 3) + a3;
  if ( v12 )
  {
    v13 = *(_QWORD *)(v12 + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d index_offset:0x%x\n", "ipa3_nat_create_init_cmd", 1154, *((_DWORD *)a1 + 3));
      v12 = ipa3_ctx;
    }
    result = *(_QWORD *)(v12 + 34160);
    if ( result )
    {
      result = ipc_log_string(
                 result,
                 "ipa %s:%d index_offset:0x%x\n",
                 "ipa3_nat_create_init_cmd",
                 1154,
                 *((_DWORD *)a1 + 3));
      v12 = ipa3_ctx;
    }
    *(_QWORD *)(a4 + 32) = *((unsigned int *)a1 + 4) + a3;
    if ( v12 )
    {
      v14 = *(_QWORD *)(v12 + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d index_expn_offset:0x%x\n", "ipa3_nat_create_init_cmd", 1158, *((_DWORD *)a1 + 4));
        v12 = ipa3_ctx;
      }
      result = *(_QWORD *)(v12 + 34160);
      if ( result )
      {
        result = ipc_log_string(
                   result,
                   "ipa %s:%d index_expn_offset:0x%x\n",
                   "ipa3_nat_create_init_cmd",
                   1158,
                   *((_DWORD *)a1 + 4));
        v12 = ipa3_ctx;
      }
    }
  }
  else
  {
    *(_QWORD *)(a4 + 32) = *((unsigned int *)a1 + 4) + a3;
  }
  if ( *(_DWORD *)(v12 + 32240) < 0xEu )
  {
    *(_DWORD *)(a4 + 44) = *((_DWORD *)a1 + 6);
    v17 = (const void *)(a4 + 44);
    if ( !v12 )
      goto LABEL_28;
    v18 = *(_QWORD *)(v12 + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d Public IP address:%pI4h\n", "ipa3_nat_create_init_cmd", 1169, v17);
      v12 = ipa3_ctx;
    }
    result = *(_QWORD *)(v12 + 34160);
    if ( result )
    {
      result = ipc_log_string(result, "ipa %s:%d Public IP address:%pI4h\n", "ipa3_nat_create_init_cmd", 1169, v17);
      goto LABEL_28;
    }
  }
  else
  {
    v15 = *(_DWORD *)(**(_QWORD **)(v12 + 34176) + 288LL);
    *(_DWORD *)(a4 + 44) = v15;
    if ( !v12 )
    {
LABEL_28:
      v12 = ipa3_ctx;
      goto LABEL_29;
    }
    v16 = *(_QWORD *)(v12 + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d pdn config base:0x%x\n", "ipa3_nat_create_init_cmd", 1166, v15);
      v12 = ipa3_ctx;
    }
    result = *(_QWORD *)(v12 + 34160);
    if ( result )
    {
      result = ipc_log_string(
                 result,
                 "ipa %s:%d pdn config base:0x%x\n",
                 "ipa3_nat_create_init_cmd",
                 1166,
                 *(_DWORD *)(a4 + 44));
      goto LABEL_28;
    }
  }
LABEL_29:
  if ( v12 )
  {
    v19 = *(_QWORD *)(v12 + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d return\n", "ipa3_nat_create_init_cmd", 1172);
      v12 = ipa3_ctx;
    }
    result = *(_QWORD *)(v12 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d return\n", "ipa3_nat_create_init_cmd", 1172);
  }
  return result;
}
