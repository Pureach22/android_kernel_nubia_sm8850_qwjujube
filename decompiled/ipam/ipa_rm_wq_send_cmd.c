__int64 __fastcall ipa_rm_wq_send_cmd(int a1, int a2, int a3, char a4)
{
  __int64 v8; // x2
  __int64 v9; // x8

  v8 = _kmalloc_cache_noprof(ipc_log_string, 2336, 48);
  if ( !v8 )
    return 4294967284LL;
  *(_QWORD *)v8 = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v8 + 8) = v8 + 8;
  *(_QWORD *)(v8 + 16) = v8 + 8;
  *(_QWORD *)(v8 + 24) = ipa_rm_wq_handler;
  v9 = ipa_rm_ctx;
  *(_DWORD *)(v8 + 32) = a1;
  *(_DWORD *)(v8 + 36) = a2;
  *(_DWORD *)(v8 + 40) = a3;
  *(_BYTE *)(v8 + 44) = a4 & 1;
  return queue_work_on(32, *(_QWORD *)(v9 + 8), v8) & 1;
}
