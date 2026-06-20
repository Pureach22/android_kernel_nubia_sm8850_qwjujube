__int64 rmnet_module_hook_offload_chain_end()
{
  __int64 lock; // x0
  __int64 (__fastcall *v1)(__int64); // x8
  unsigned int v2; // w19

  lock = _rcu_read_lock();
  v1 = (__int64 (__fastcall *)(__int64))off_2F8D8;
  if ( off_2F8D8 )
  {
    if ( *((_DWORD *)off_2F8D8 - 1) != -440107680 )
      __break(0x8228u);
    lock = v1(lock);
    v2 = 1;
  }
  else
  {
    v2 = 0;
  }
  _rcu_read_unlock(lock);
  return v2;
}
