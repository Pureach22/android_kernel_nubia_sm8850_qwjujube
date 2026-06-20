void __fastcall binder_trans_for_freeze_notify(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 lock; // x0
  int v9; // w19
  unsigned __int64 v10; // x2
  __int64 v11; // x19
  __int64 v12; // x2

  if ( a2 )
  {
    v5 = *(_QWORD *)(a2 + 72);
    if ( v5 )
    {
      if ( a5 && *(_DWORD *)(*(_QWORD *)(v5 + 2296) + 8LL) >= 0x2711u && (*(_BYTE *)(a5 + 20) & 1) != 0 )
      {
        if ( (v6 = *(_QWORD *)(*(_QWORD *)(v5 + 2872) + 80LL)) != 0 && (*(_BYTE *)(v6 + 1904) & 1) != 0
          || (v7 = a2,
              lock = _rcu_read_lock(),
              v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 2872) + 40LL) + 216LL) & 0xE,
              _rcu_read_unlock(lock),
              a2 = v7,
              v9) )
        {
          v10 = *(_QWORD *)(a2 + 552);
          if ( v10 <= 0xC800 )
          {
            v11 = a2;
            printk(&unk_70F5, *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a2 + 72) + 2296LL) + 8LL), v10);
            send_unfreeze_event((__int64)"BINDER", *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 72) + 2296LL) + 8LL), v12);
          }
        }
      }
    }
  }
}
