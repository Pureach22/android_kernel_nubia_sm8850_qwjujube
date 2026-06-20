__int64 init_module()
{
  return _platform_driver_register(msm_m31_eusb2_phy_driver, &_this_module);
}
