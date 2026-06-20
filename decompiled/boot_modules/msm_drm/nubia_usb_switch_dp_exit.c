__int64 nubia_usb_switch_dp_exit()
{
  return platform_driver_unregister(usb_switch_dp_driver);
}
