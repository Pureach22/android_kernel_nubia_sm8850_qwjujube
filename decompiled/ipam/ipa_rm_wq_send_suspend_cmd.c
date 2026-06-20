__int64 __fastcall ipa_rm_wq_send_suspend_cmd(int a1, int a2, int a3)
{
  __int64 v6; // x2
  __int64 v7; // x8

  v6 = _kmalloc_cache_noprof(ipc_log_string, 2336, 48);
  if ( !v6 )
    return 4294967284LL;
  *(_QWORD *)v6 = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v6 + 8) = v6 + 8;
  *(_QWORD *)(v6 + 16) = v6 + 8;
  *(_QWORD *)(v6 + 24) = ipa_rm_wq_suspend_handler;
  v7 = ipa_rm_ctx;
  *(_DWORD *)(v6 + 32) = a1;
  *(_DWORD *)(v6 + 36) = a2;
  *(_DWORD *)(v6 + 40) = a3;
  return queue_work_on(32, *(_QWORD *)(v7 + 8), v6) & 1;
}
