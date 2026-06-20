__int64 rmnet_perf_tether_set_hooks()
{
  return rmnet_module_hook_register(&rmnet_perf_tether_module_hooks, 3);
}
