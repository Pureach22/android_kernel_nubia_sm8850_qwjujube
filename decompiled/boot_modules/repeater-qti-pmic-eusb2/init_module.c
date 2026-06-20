__int64 init_module()
{
  return _platform_driver_register(eusb2_repeater_driver, &_this_module);
}
