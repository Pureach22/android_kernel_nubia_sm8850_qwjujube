__int64 __fastcall rmnet_module_hook_shs_skb_entry(_DWORD *a1, __int64 a2, __int64 a3)
{
  __int64 lock; // x0
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  unsigned int v8; // w19

  lock = _rcu_read_lock();
  v7 = (__int64 (__fastcall *)(__int64, __int64))off_2F8E0;
  if ( off_2F8E0 )
  {
    if ( *((_DWORD *)off_2F8E0 - 1) != -1204700009 )
      __break(0x8228u);
    lock = v7(a2, a3);
    if ( a1 )
      *a1 = lock;
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  _rcu_read_unlock(lock);
  return v8;
}
