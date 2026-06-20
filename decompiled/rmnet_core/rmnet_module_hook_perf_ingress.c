__int64 __fastcall rmnet_module_hook_perf_ingress(_DWORD *a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 (__fastcall *v5)(__int64); // x8
  unsigned int v6; // w19

  lock = _rcu_read_lock();
  v5 = (__int64 (__fastcall *)(__int64))off_2F910;
  if ( off_2F910 )
  {
    if ( *((_DWORD *)off_2F910 - 1) != -1282094308 )
      __break(0x8228u);
    lock = v5(a2);
    if ( a1 )
      *a1 = lock;
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  _rcu_read_unlock(lock);
  return v6;
}
