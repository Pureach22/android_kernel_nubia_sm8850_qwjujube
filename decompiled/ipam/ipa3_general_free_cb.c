__int64 __fastcall ipa3_general_free_cb(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0

  if ( a1 )
    return kfree(a1);
  result = printk(&unk_3B18C1, "ipa3_general_free_cb");
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Null buffer\n", "ipa3_general_free_cb", 2561);
      v2 = ipa3_ctx;
    }
    result = *(_QWORD *)(v2 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Null buffer\n", "ipa3_general_free_cb", 2561);
  }
  return result;
}
