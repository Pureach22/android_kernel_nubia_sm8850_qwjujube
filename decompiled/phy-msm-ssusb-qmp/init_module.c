__int64 init_module()
{
  return _platform_driver_register(msm_ssphy_qmp_driver, &_this_module);
}
