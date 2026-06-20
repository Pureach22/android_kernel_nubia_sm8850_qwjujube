__int64 init_module()
{
  return _platform_driver_register(sdhci_msm_driver, &_this_module);
}
