__int64 __fastcall rmnet_module_hook_wlan_flow_match(__int64 a1)
{
  __int64 lock; // x0
  __int64 (__fastcall *v3)(__int64); // x8
  unsigned int v4; // w19

  lock = _rcu_read_lock();
  v3 = (__int64 (__fastcall *)(__int64))off_2F938;
  if ( off_2F938 )
  {
    if ( *((_DWORD *)off_2F938 - 1) != 303786302 )
      __break(0x8228u);
    lock = v3(a1);
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  _rcu_read_unlock(lock);
  return v4;
}
