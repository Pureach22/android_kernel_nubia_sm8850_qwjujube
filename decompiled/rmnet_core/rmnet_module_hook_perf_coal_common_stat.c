__int64 __fastcall rmnet_module_hook_perf_coal_common_stat(unsigned int a1, unsigned int a2)
{
  __int64 lock; // x0
  void *v5; // x8
  unsigned int v6; // w19

  lock = _rcu_read_lock();
  v5 = off_2F970;
  if ( off_2F970 )
  {
    if ( *((_DWORD *)off_2F970 - 1) != -1176515768 )
      __break(0x8228u);
    lock = ((__int64 (__fastcall *)(_QWORD, _QWORD))v5)(a1, a2);
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  _rcu_read_unlock(lock);
  return v6;
}
