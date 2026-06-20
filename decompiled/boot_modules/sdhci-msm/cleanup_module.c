__int64 cleanup_module()
{
  return platform_driver_unregister(sdhci_msm_driver);
}
