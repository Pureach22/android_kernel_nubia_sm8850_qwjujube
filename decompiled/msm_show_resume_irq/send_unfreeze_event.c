__int64 __fastcall send_unfreeze_event(__int64 a1, int a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x1

  if ( !state )
    return printk(&unk_6FE0, 0, a3);
  v5 = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 48);
  wsdata = v5;
  if ( !v5 )
    return printk(&unk_7391, v6, v7);
  *(_QWORD *)v5 = a1;
  *(_QWORD *)(v5 + 16) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(v5 + 8) = a2;
  *(_QWORD *)(v5 + 24) = v5 + 24;
  *(_QWORD *)(v5 + 32) = v5 + 24;
  v8 = unfreeze_eventqueue;
  *(_QWORD *)(v5 + 40) = sendevent_handler;
  return queue_work_on(32, v8, v5 + 16);
}
