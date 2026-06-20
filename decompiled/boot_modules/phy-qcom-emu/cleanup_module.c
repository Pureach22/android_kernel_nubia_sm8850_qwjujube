__int64 cleanup_module()
{
  return platform_driver_unregister(qcusb_emu_phy_driver);
}
