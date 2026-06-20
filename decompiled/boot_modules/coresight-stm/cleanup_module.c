__int64 cleanup_module()
{
  return coresight_remove_driver(&stm_driver, stm_platform_driver);
}
