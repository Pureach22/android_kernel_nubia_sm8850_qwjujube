__int64 __fastcall rmnet_wlan_add_ll_tuple(__int64 *a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x9
  __int64 v4; // x10
  unsigned __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 v10; // x0

  mutex_lock(&rmnet_wlan_ll_tuple_mutex);
  v2 = (_QWORD *)_kmalloc_cache_noprof(ipv6_stub, 3520, 40);
  if ( v2 )
  {
    v3 = a1[3];
    v4 = a1[4];
    v5 = (unsigned __int64)v2;
    v2[2] = a1[2];
    v2[3] = v3;
    v7 = *a1;
    v6 = a1[1];
    v2[4] = v4;
    *v2 = v7;
    v2[1] = v6;
    v8 = raw_spin_lock_irqsave(&rmnet_wlan_tuple_lock);
    v9 = rmnet_wlan_ll_tuple_cache;
    atomic_store(v5, (unsigned __int64 *)&rmnet_wlan_ll_tuple_cache);
    v10 = raw_spin_unlock_irqrestore(&rmnet_wlan_tuple_lock, v8);
    synchronize_rcu(v10);
    if ( v9 )
    {
      kfree(v9);
      LODWORD(v9) = 0;
    }
  }
  else
  {
    LODWORD(v9) = -12;
  }
  mutex_unlock(&rmnet_wlan_ll_tuple_mutex);
  return (unsigned int)v9;
}
