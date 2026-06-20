__int64 __fastcall ipa3_finish_read_memory_device(__int64 a1, int a2, int a3)
{
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0

  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d In\n", "ipa3_finish_read_memory_device", 2442);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d In\n", "ipa3_finish_read_memory_device", 2442);
  }
  if ( *(_BYTE *)(a1 + 221) == 1 )
  {
    result = printk(&unk_3AC7B1, a1);
    v10 = ipa3_ctx;
    if ( !ipa3_ctx )
      return result;
    goto LABEL_14;
  }
  if ( a2 )
    printk(&unk_3A31B8, a1);
  if ( a3 )
    printk(&unk_3DB0FF, a1);
  result = printk(&unk_3D82B4, a1);
  v10 = ipa3_ctx;
  if ( ipa3_ctx )
  {
LABEL_14:
    v11 = *(_QWORD *)(v10 + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Out\n", "ipa3_finish_read_memory_device", 2467);
      v10 = ipa3_ctx;
    }
    result = *(_QWORD *)(v10 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_finish_read_memory_device", 2467);
  }
  return result;
}
