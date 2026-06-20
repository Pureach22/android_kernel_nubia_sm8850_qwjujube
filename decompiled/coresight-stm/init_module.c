__int64 init_module()
{
  return coresight_init_driver("stm", &stm_driver, stm_platform_driver);
}
