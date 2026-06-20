__int64 __fastcall rmnet_wlan_act_encap_port_drop(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 lock; // x0
  unsigned __int64 *v5; // x21
  unsigned __int64 *v6; // x8
  _QWORD *v7; // x20
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x8
  _QWORD *v11; // x20

  v3 = (unsigned __int16)a1;
  lock = _rcu_read_lock(a1);
  v5 = &rmnet_wlan_act_encap_drop_hash[(unsigned int)(1640531527 * v3) >> 28];
  v6 = v5;
  while ( 1 )
  {
    v6 = (unsigned __int64 *)*v6;
    if ( !v6 )
      break;
    if ( *((unsigned __int16 *)v6 + 16) == v3 )
    {
      _rcu_read_unlock(lock);
      v7 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("Encap port already present");
      if ( v7 )
        *v7 = "Encap port already present";
      return 4294967279LL;
    }
  }
  _rcu_read_unlock(lock);
  v9 = _kmalloc_cache_noprof(ipv6_stub, 3520, 40);
  if ( v9 )
  {
    v10 = *v5;
    *(_WORD *)(v9 + 32) = v3;
    *(_QWORD *)v9 = v10;
    *(_QWORD *)(v9 + 8) = v5;
    atomic_store(v9, v5);
    if ( v10 )
      *(_QWORD *)(v10 + 8) = v9;
    rmnet_wlan_stats_update(16);
    return 0;
  }
  else
  {
    v11 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Cannot allocate encap port memory");
    if ( v11 )
      *v11 = "Cannot allocate encap port memory";
    return 4294967284LL;
  }
}
