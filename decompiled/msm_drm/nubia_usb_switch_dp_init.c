__int64 nubia_usb_switch_dp_init()
{
  _platform_driver_register(usb_switch_dp_driver, &_this_module);
  return 0;
}
