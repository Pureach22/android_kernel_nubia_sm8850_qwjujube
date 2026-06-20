__int64 rmnet_perf_unset_hooks()
{
  __int64 v0; // x0

  v0 = rmnet_module_hook_unregister_no_sync("\b", 10);
  return synchronize_rcu(v0);
}
