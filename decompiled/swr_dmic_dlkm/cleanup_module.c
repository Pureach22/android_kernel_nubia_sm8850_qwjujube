__int64 cleanup_module()
{
  return swr_driver_unregister(&swr_dmic_driver);
}
