__int64 __fastcall ipa3_rmnet_mem_notifier(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d New pool size: %lu\n", "ipa3_rmnet_mem_notifier", 1448, a2);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d New pool size: %lu\n", "ipa3_rmnet_mem_notifier", 1448, a2);
      v3 = ipa3_ctx;
    }
  }
  *(_DWORD *)(v3 + 48792) = a2;
  return 0;
}
