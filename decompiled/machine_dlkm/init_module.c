__int64 init_module()
{
  snd_card_sysfs_init();
  return _platform_driver_register(canoe_asoc_machine_driver, &_this_module);
}
