__int64 cleanup_module()
{
  return platform_driver_unregister(&m31eusb2_phy_driver);
}
