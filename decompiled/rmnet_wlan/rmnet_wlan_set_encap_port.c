__int64 __fastcall rmnet_wlan_set_encap_port(unsigned __int16 a1, __int64 a2)
{
  int v2; // w20
  __int64 v4; // x0
  __int64 lock; // x0
  unsigned __int64 *v6; // x21
  unsigned __int64 *v7; // x8
  _QWORD *v8; // x20
  unsigned int v9; // w19
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x8
  _QWORD *v12; // x20

  v2 = a1;
  v4 = mutex_lock(&rmnet_wlan_encap_mutex);
  lock = _rcu_read_lock(v4);
  v6 = (unsigned __int64 *)((char *)&rmnet_wlan_encap_hash + 8 * ((unsigned int)(1640531527 * v2) >> 28));
  v7 = v6;
  while ( 1 )
  {
    v7 = (unsigned __int64 *)*v7;
    if ( !v7 )
      break;
    if ( *((unsigned __int16 *)v7 + 16) == v2 )
    {
      _rcu_read_unlock(lock);
      v8 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("Encap port already present");
      if ( v8 )
        *v8 = "Encap port already present";
      v9 = -17;
      goto LABEL_15;
    }
  }
  _rcu_read_unlock(lock);
  v10 = _kmalloc_cache_noprof(ipv6_stub, 3520, 40);
  if ( v10 )
  {
    v11 = *v6;
    *(_WORD *)(v10 + 32) = v2;
    *(_QWORD *)v10 = v11;
    *(_QWORD *)(v10 + 8) = v6;
    atomic_store(v10, v6);
    if ( v11 )
      *(_QWORD *)(v11 + 8) = v10;
    rmnet_wlan_stats_update(14);
    v9 = 0;
  }
  else
  {
    v12 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Cannot allocate encap port memory");
    if ( v12 )
      *v12 = "Cannot allocate encap port memory";
    v9 = -12;
  }
LABEL_15:
  mutex_unlock(&rmnet_wlan_encap_mutex);
  return v9;
}
