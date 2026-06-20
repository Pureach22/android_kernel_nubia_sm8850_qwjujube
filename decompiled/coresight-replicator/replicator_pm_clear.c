__int64 replicator_pm_clear()
{
  __int64 result; // x0

  cpu_pm_unregister_notifier(&replicator_cpu_pm_nb);
  result = (unsigned int)hp_online;
  if ( hp_online )
  {
    result = _cpuhp_remove_state();
    hp_online = 0;
  }
  return result;
}
