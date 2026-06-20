__int64 rmnet_wlan_del_ll_tuple()
{
  __int64 v0; // x0
  __int64 v1; // x19
  __int64 v2; // x0

  mutex_lock(&rmnet_wlan_ll_tuple_mutex);
  v0 = raw_spin_lock_irqsave(&rmnet_wlan_tuple_lock);
  v1 = rmnet_wlan_ll_tuple_cache;
  rmnet_wlan_ll_tuple_cache = 0;
  v2 = raw_spin_unlock_irqrestore(&rmnet_wlan_tuple_lock, v0);
  synchronize_rcu(v2);
  if ( v1 )
    kfree(v1);
  mutex_unlock(&rmnet_wlan_ll_tuple_mutex);
  return 0;
}
