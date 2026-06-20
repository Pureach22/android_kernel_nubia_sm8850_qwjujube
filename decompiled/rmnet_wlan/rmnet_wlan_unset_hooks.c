__int64 rmnet_wlan_unset_hooks()
{
  __int64 v0; // x0

  v0 = rmnet_module_hook_unregister_no_sync(&rmnet_wlan_module_hooks, 2);
  return synchronize_rcu(v0);
}
