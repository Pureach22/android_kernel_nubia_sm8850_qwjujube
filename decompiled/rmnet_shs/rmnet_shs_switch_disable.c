__int64 rmnet_shs_switch_disable()
{
  return rmnet_module_hook_unregister_no_sync(&rmnet_shs_switch_hook, 1);
}
