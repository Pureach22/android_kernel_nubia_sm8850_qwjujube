__int64 cleanup_module()
{
  return platform_driver_unregister(msm_m31_eusb2_phy_driver);
}
