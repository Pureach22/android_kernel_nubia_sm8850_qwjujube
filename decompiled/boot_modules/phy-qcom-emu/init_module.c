__int64 init_module()
{
  return _platform_driver_register(qcusb_emu_phy_driver, &_this_module);
}
