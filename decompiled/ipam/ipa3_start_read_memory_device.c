__int64 __fastcall ipa3_start_read_memory_device(__int64 result, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x21
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x0
  int v11; // w8
  const char *v12; // x23
  __int64 v13; // x22
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v7 = result;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(result + 221);
  v21 = 0;
  if ( v8 == 1 )
  {
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d In: v6\n", "ipa3_start_read_memory_device", 2344);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d In: v6\n", "ipa3_start_read_memory_device", 2344);
    }
    printk(&unk_3A6635, v7);
    printk(&unk_3CF6AF, v7);
    printk(&unk_3F7BBB, v7);
    v19 = *(_QWORD *)(v7 + 272);
    if ( v19 )
      ipa3_read_table(v19, (unsigned int)(*(_DWORD *)(v7 + 288) + 1), a3, &v21, a2);
    printk(&unk_3E9306, v7);
    result = *(_QWORD *)(v7 + 280);
    if ( result )
      result = ipa3_read_table(result, *(unsigned int *)(v7 + 292), a3, &v21, a2);
  }
  if ( *(_BYTE *)(v7 + 220) == 1 )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d In: v4\n", "ipa3_start_read_memory_device", 2379);
        v9 = ipa3_ctx;
      }
      result = *(_QWORD *)(v9 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d In: v4\n", "ipa3_start_read_memory_device", 2379);
    }
    v11 = *(_DWORD *)(v7 + 344);
    if ( v11 == 1 )
    {
      if ( *(_BYTE *)(v7 + 357) != 1 )
        goto LABEL_15;
      v12 = "SRAM based table";
      a3 = a4;
      v13 = v7 + 456;
      if ( v7 == -456 )
        goto LABEL_15;
    }
    else
    {
      if ( v11 )
        goto LABEL_15;
      if ( (*(_BYTE *)(v7 + 356) & 1) == 0 )
        goto LABEL_15;
      v12 = "DDR based table";
      v13 = v7 + 360;
      if ( v7 == -360 )
        goto LABEL_15;
    }
    printk(&unk_3DB0E6, v12);
    printk(&unk_3F4D5B, v12);
    printk(&unk_3C394E, v12);
    v20 = *(_QWORD *)(v13 + 64);
    if ( v20 )
      ipa3_read_table(v20, (unsigned int)(*(_DWORD *)(v13 + 48) + 1), a3, &v21, a2);
    printk(&unk_3AC78A, v12);
    result = *(_QWORD *)(v13 + 72);
    if ( result )
      result = ipa3_read_table(result, *(unsigned int *)(v13 + 52), a3, &v21, a2);
  }
LABEL_15:
  v14 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Out\n", "ipa3_start_read_memory_device", 2434);
      v14 = ipa3_ctx;
    }
    result = *(_QWORD *)(v14 + 34160);
    if ( result )
      result = ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_start_read_memory_device", 2434);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
