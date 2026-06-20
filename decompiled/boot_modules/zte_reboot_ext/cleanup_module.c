__int64 cleanup_module()
{
  return platform_driver_unregister(zte_reboot_ext_driver);
}
