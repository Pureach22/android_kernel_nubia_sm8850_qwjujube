__int64 __fastcall ipa3_nat_ipv6ct_create_init_cmd(
        __int64 result,
        char a2,
        __int64 a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned __int16 a7,
        unsigned __int16 a8,
        const char *a9)
{
  __int64 v13; // x21
  __int64 v15; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0

  *(_QWORD *)result = a3 + a5;
  v13 = result;
  v15 = ipa3_ctx;
  *(_BYTE *)(result + 16) = a2;
  *(_BYTE *)(result + 17) = a2;
  if ( !v15 )
  {
    *(_QWORD *)(result + 8) = a3 + a6;
LABEL_27:
    *(_BYTE *)(v13 + 22) = a4;
LABEL_28:
    *(_WORD *)(v13 + 18) = a7;
LABEL_29:
    *(_WORD *)(v13 + 20) = a8;
    return result;
  }
  v17 = *(_QWORD *)(v15 + 34152);
  if ( v17 )
  {
    ipc_log_string(v17, "ipa %s:%d %s base table offset:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 970, a9, a5);
    v15 = ipa3_ctx;
  }
  result = *(_QWORD *)(v15 + 34160);
  if ( result )
  {
    result = ipc_log_string(
               result,
               "ipa %s:%d %s base table offset:0x%x\n",
               "ipa3_nat_ipv6ct_create_init_cmd",
               970,
               a9,
               a5);
    v15 = ipa3_ctx;
  }
  *(_QWORD *)(v13 + 8) = a3 + a6;
  if ( !v15 )
    goto LABEL_27;
  v18 = *(_QWORD *)(v15 + 34152);
  if ( v18 )
  {
    ipc_log_string(v18, "ipa %s:%d %s expn table offset:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 973, a9, a6);
    v15 = ipa3_ctx;
  }
  result = *(_QWORD *)(v15 + 34160);
  if ( result )
  {
    result = ipc_log_string(
               result,
               "ipa %s:%d %s expn table offset:0x%x\n",
               "ipa3_nat_ipv6ct_create_init_cmd",
               973,
               a9,
               a6);
    v15 = ipa3_ctx;
  }
  *(_BYTE *)(v13 + 22) = a4;
  if ( !v15 )
    goto LABEL_28;
  v19 = *(_QWORD *)(v15 + 34152);
  if ( v19 )
  {
    ipc_log_string(v19, "ipa %s:%d %s table index:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 976, a9, a4);
    v15 = ipa3_ctx;
  }
  result = *(_QWORD *)(v15 + 34160);
  if ( result )
  {
    result = ipc_log_string(result, "ipa %s:%d %s table index:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 976, a9, a4);
    v15 = ipa3_ctx;
  }
  *(_WORD *)(v13 + 18) = a7;
  if ( !v15 )
    goto LABEL_29;
  v20 = *(_QWORD *)(v15 + 34152);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d %s base table size:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 979, a9, a7);
    v15 = ipa3_ctx;
  }
  result = *(_QWORD *)(v15 + 34160);
  if ( result )
  {
    result = ipc_log_string(
               result,
               "ipa %s:%d %s base table size:0x%x\n",
               "ipa3_nat_ipv6ct_create_init_cmd",
               979,
               a9,
               a7);
    v15 = ipa3_ctx;
  }
  *(_WORD *)(v13 + 20) = a8;
  if ( v15 )
  {
    v21 = *(_QWORD *)(v15 + 34152);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d %s expansion table size:0x%x\n", "ipa3_nat_ipv6ct_create_init_cmd", 983, a9, a8);
      v15 = ipa3_ctx;
    }
    result = *(_QWORD *)(v15 + 34160);
    if ( result )
      return ipc_log_string(
               result,
               "ipa %s:%d %s expansion table size:0x%x\n",
               "ipa3_nat_ipv6ct_create_init_cmd",
               983,
               a9,
               a8);
  }
  return result;
}
