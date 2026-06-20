__int64 __fastcall rmnet_wlan_add_tuples(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x22
  unsigned __int16 *v8; // x28
  __int64 lock; // x0
  int v10; // w8
  __int64 *v11; // x9
  int v12; // w10
  _QWORD *v13; // x28
  unsigned __int64 *v14; // x0
  int v15; // w8
  unsigned __int64 *v16; // x10
  unsigned __int64 v17; // x8
  _QWORD *v18; // x20
  unsigned int v19; // w19

  v6 = mutex_lock(&rmnet_wlan_tuple_mutex);
  if ( a2 )
  {
    v7 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v8 = (unsigned __int16 *)(a1 + 8 * v7);
      lock = _rcu_read_lock(v6);
      v10 = *v8;
      v11 = (__int64 *)rmnet_wlan_tuple_hash[(unsigned int)(1640531527 * v10) >> 28];
      if ( v11 )
      {
        v12 = *((unsigned __int8 *)v8 + 4);
        do
        {
          if ( *((unsigned __int8 *)v11 + 36) == v12 && *((unsigned __int8 *)v11 + 37) == *((unsigned __int8 *)v8 + 5) )
          {
            if ( v12 == 50 )
            {
              if ( *((_DWORD *)v11 + 8) == *(_DWORD *)v8 )
              {
LABEL_13:
                _rcu_read_unlock(lock);
                v13 = *(_QWORD **)(a3 + 64);
                v6 = do_trace_netlink_extack("Tuple already present");
                if ( v13 )
                  *v13 = "Tuple already present";
                goto LABEL_4;
              }
            }
            else if ( *((unsigned __int16 *)v11 + 16) == v10 )
            {
              goto LABEL_13;
            }
          }
          v11 = (__int64 *)*v11;
        }
        while ( v11 );
      }
      _rcu_read_unlock(lock);
      v14 = (unsigned __int64 *)_kmalloc_cache_noprof(ipv6_stub, 3520, 40);
      if ( !v14 )
        break;
      v15 = (unsigned __int16)*(_QWORD *)v8;
      v14[4] = *(_QWORD *)v8;
      v16 = &rmnet_wlan_tuple_hash[(unsigned int)(1640531527 * v15) >> 28];
      v17 = *v16;
      *v14 = *v16;
      v14[1] = (unsigned __int64)v16;
      atomic_store((unsigned __int64)v14, v16);
      if ( v17 )
        *(_QWORD *)(v17 + 8) = v14;
      v6 = rmnet_wlan_stats_update(0);
      ++rmnet_wlan_tuple_count;
LABEL_4:
      if ( ++v7 == a2 )
        goto LABEL_21;
    }
    v18 = *(_QWORD **)(a3 + 64);
    do_trace_netlink_extack("Cannot allocate tuple memory");
    if ( v18 )
      *v18 = "Cannot allocate tuple memory";
    v19 = -12;
  }
  else
  {
LABEL_21:
    v19 = 0;
  }
  mutex_unlock(&rmnet_wlan_tuple_mutex);
  return v19;
}
