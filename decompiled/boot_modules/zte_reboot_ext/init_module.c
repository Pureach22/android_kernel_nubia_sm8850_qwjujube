__int64 init_module()
{
  return _platform_driver_register(zte_reboot_ext_driver, &_this_module);
}
