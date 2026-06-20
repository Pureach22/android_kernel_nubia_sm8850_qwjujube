__int64 rmnet_perf_set_hooks()
{
  return rmnet_module_hook_register("\b", 10);
}
