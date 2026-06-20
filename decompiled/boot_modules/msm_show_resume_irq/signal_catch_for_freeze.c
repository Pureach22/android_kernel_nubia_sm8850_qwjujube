void __fastcall signal_catch_for_freeze(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 lock; // x0
  int v7; // w21
  __int64 v8; // x2
  __int64 v9; // x8
  __int64 v11; // x8
  void *v12; // x0

  if ( a2 > 0xB || ((1 << a2) & 0xA48) == 0 )
    goto LABEL_6;
  lock = _rcu_read_lock();
  v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a4 + 2872) + 40LL) + 216LL) & 0xE;
  _rcu_read_unlock(lock);
  if ( v7 )
  {
    send_unfreeze_event_withpid(
      (__int64)"KILL",
      *(unsigned int *)(*(_QWORD *)(a4 + 2296) + 8LL),
      *(_DWORD *)(a4 + 1800));
    v11 = *(_QWORD *)(a4 + 2296);
    v12 = &unk_71E0;
  }
  else
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a4 + 2872) + 80LL);
    if ( !v9 || *(_BYTE *)(v9 + 1904) != 1 )
      goto LABEL_6;
    send_unfreeze_event((__int64)"KILL", *(_DWORD *)(*(_QWORD *)(a4 + 2296) + 8LL), v8);
    v11 = *(_QWORD *)(a4 + 2296);
    v12 = &unk_70C2;
  }
  printk(v12, a2, *(unsigned int *)(v11 + 8));
LABEL_6:
  if ( a2 - 19 <= 1 || a2 == 2 )
  {
    if ( a4 )
      printk(&unk_7033, a2, *(unsigned int *)(*(_QWORD *)(a4 + 2296) + 8LL));
  }
}
