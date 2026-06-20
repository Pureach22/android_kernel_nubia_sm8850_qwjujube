__int64 __fastcall rmnet_module_hook_perf_set_thresh(unsigned int a1, unsigned int a2)
{
  __int64 lock; // x0
  void *v5; // x8
  unsigned int v6; // w19

  lock = _rcu_read_lock();
  v5 = off_2F920;
  if ( off_2F920 )
  {
    if ( *((_DWORD *)off_2F920 - 1) != -22928302 )
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
