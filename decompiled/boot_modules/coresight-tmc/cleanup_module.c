__int64 cleanup_module()
{
  __int64 result; // x0

  coresight_remove_driver(&tmc_driver, tmc_platform_driver);
  cpu_pm_unregister_notifier(&tmc_cpu_pm_nb);
  result = (unsigned int)hp_online;
  if ( hp_online )
  {
    result = _cpuhp_remove_state();
    hp_online = 0;
  }
  return result;
}
