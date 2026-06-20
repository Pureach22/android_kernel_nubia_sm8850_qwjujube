void __fastcall binder_catch_for_freeze_notify(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v6; // x19
  unsigned int v7; // w1
  __int64 v8; // x8
  __int64 lock; // x0
  int v10; // w20

  if ( a2 )
  {
    v6 = *(_QWORD *)(a2 + 72);
    if ( v6 )
    {
      v7 = *(_DWORD *)(*(_QWORD *)(v6 + 2296) + 8LL);
      if ( v7 >= 0x2711 && (a6 & 1) != 0 )
      {
        v8 = *(_QWORD *)(*(_QWORD *)(v6 + 2872) + 80LL);
        if ( !v8 || (*(_BYTE *)(v8 + 1904) & 1) == 0 )
        {
          lock = _rcu_read_lock();
          v10 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 2872) + 40LL) + 216LL) & 0xE;
          _rcu_read_unlock(lock);
          if ( !v10 )
            return;
          v7 = *(_DWORD *)(*(_QWORD *)(v6 + 2296) + 8LL);
        }
        send_unfreeze_event((__int64)"BINDER", v7, a3);
      }
    }
  }
}
