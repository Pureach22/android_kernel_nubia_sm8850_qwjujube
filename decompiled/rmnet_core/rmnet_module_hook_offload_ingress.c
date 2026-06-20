__int64 __fastcall rmnet_module_hook_offload_ingress(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned int v6; // w19

  lock = _rcu_read_lock();
  v5 = (__int64 (__fastcall *)(__int64, __int64))rmnet_module_hooks;
  if ( rmnet_module_hooks )
  {
    if ( *((_DWORD *)rmnet_module_hooks - 1) != 508925349 )
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
