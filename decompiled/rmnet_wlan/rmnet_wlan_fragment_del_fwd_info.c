__int64 __fastcall rmnet_wlan_fragment_del_fwd_info(__int64 a1)
{
  __int64 lock; // x0
  __int64 i; // x8
  _QWORD *j; // x11

  lock = _rcu_read_lock(a1);
  for ( i = 0; i != 16; ++i )
  {
    for ( j = (_QWORD *)rmnet_wlan_fragment_hash[i]; j; j = (_QWORD *)*j )
    {
      if ( j[13] == a1 )
        j[13] = -22;
    }
  }
  return _rcu_read_unlock(lock);
}
