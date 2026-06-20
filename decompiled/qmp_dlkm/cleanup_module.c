__int64 cleanup_module()
{
  return swr_driver_unregister(qmp_sdca_dmic_driver);
}
