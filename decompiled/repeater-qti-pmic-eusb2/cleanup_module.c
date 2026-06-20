__int64 cleanup_module()
{
  return platform_driver_unregister(eusb2_repeater_driver);
}
