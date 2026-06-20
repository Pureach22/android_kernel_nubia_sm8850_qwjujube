__int64 cleanup_module()
{
  __int64 v0; // x0

  ieee80211_iface_exit();
  drop_reasons_unregister_subsys(2);
  v0 = drop_reasons_unregister_subsys(1);
  return rcu_barrier(v0);
}
