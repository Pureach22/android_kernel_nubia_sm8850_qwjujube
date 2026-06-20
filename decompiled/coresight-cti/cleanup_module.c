__int64 cleanup_module()
{
  coresight_remove_cti_ops();
  return amba_driver_unregister(&cti_driver);
}
