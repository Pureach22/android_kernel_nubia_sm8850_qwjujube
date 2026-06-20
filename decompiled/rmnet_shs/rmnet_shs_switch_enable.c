__int64 rmnet_shs_switch_enable()
{
  return rmnet_module_hook_register(&rmnet_shs_switch_hook, 1);
}
