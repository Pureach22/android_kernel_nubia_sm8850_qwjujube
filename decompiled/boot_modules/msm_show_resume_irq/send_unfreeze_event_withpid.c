__int64 __fastcall send_unfreeze_event_withpid(__int64 a1, __int64 a2, int a3)
{
  int v5; // w20
  __int64 v6; // x2
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x1

  v5 = a2;
  printk(&unk_72CE, a2, a1);
  if ( !state )
    return printk(&unk_6FE0, 0, v6);
  v7 = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 48);
  wsdata = v7;
  if ( !v7 )
    return printk(&unk_7391, v8, v9);
  *(_QWORD *)v7 = a1;
  *(_QWORD *)(v7 + 16) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(v7 + 8) = v5;
  *(_DWORD *)(v7 + 12) = a3;
  *(_QWORD *)(v7 + 24) = v7 + 24;
  *(_QWORD *)(v7 + 32) = v7 + 24;
  v10 = unfreeze_eventqueue;
  *(_QWORD *)(v7 + 40) = sendevent_handler;
  return queue_work_on(32, v10, v7 + 16);
}
