__int64 replicator_pm_setup()
{
  int v0; // w19

  v0 = cpu_pm_register_notifier(&replicator_cpu_pm_nb);
  if ( !v0 )
  {
    v0 = _cpuhp_setup_state(193, "arm/coresight-replicator:online", 0, replicator_online_cpu, replicator_offline_cpu, 0);
    if ( v0 < 1 )
    {
      cpu_pm_unregister_notifier(&replicator_cpu_pm_nb);
    }
    else
    {
      hp_online = v0;
      return 0;
    }
  }
  return (unsigned int)v0;
}
