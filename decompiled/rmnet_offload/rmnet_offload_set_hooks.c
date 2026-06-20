__int64 rmnet_offload_set_hooks()
{
  return rmnet_module_hook_register(&rmnet_offload_main_hook, 1);
}
