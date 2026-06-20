__int64 __fastcall rmnet_module_hook_perf_tether_ingress(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned int v6; // w19

  lock = _rcu_read_lock();
  v5 = (__int64 (__fastcall *)(__int64, __int64))off_2F8F8;
  if ( off_2F8F8 )
  {
    if ( *((_DWORD *)off_2F8F8 - 1) != -1698957408 )
      __break(0x8228u);
    lock = v5(a1, a2);
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  _rcu_read_unlock(lock);
  return v6;
}
