__int64 init_module()
{
  return _platform_driver_register(&zte_ramdisk_reboot_driver, &_this_module);
}
