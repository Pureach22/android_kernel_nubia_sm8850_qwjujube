__int64 __fastcall rmnet_module_hook_perf_coal_stat(unsigned int a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  __int64 lock; // x0
  void *v9; // x8
  unsigned int v10; // w19

  lock = _rcu_read_lock();
  v9 = off_2F978;
  if ( off_2F978 )
  {
    if ( *((_DWORD *)off_2F978 - 1) != -1159612895 )
      __break(0x8228u);
    lock = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD))v9)(a1, a2, a3, a4);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  _rcu_read_unlock(lock);
  return v10;
}
