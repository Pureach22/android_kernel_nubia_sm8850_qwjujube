__int64 init_module()
{
  __int64 v0; // x0
  __int64 v1; // x0

  v0 = tracepoint_probe_register(
         &_tracepoint_android_vh_update_topology_flags_workfn,
         android_vh_update_topology_flags_workfn,
         0);
  if ( topology_update_done == 1 )
    v0 = queue_work_on(32, system_wq, &walt_init_work);
  v1 = walt_cpufreq_cycle_cntr_driver_register(v0);
  walt_gclk_cycle_counter_driver_register(v1);
  return 0;
}
