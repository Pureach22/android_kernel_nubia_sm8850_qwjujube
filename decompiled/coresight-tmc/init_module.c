__int64 init_module()
{
  __int64 result; // x0

  result = tmc_pm_setup();
  if ( !(_DWORD)result )
    return coresight_init_driver("tmc", &tmc_driver, tmc_platform_driver);
  return result;
}
