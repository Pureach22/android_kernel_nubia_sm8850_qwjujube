__int64 rmnet_offload_unset_hooks()
{
  return rmnet_module_hook_unregister_no_sync(&rmnet_offload_main_hook, 1);
}
