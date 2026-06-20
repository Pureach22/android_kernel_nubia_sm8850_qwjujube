__int64 rmnet_wlan_set_hooks()
{
  return rmnet_module_hook_register(&rmnet_wlan_module_hooks, 2);
}
