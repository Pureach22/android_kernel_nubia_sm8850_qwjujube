__int64 init_module()
{
  unsigned int global_sysfs_nodes; // w19
  unsigned int v2; // w0

  global_sysfs_nodes = create_global_sysfs_nodes();
  if ( !global_sysfs_nodes )
  {
    global_sysfs_nodes = qcom_cluster_lpm_governor_init();
    if ( !global_sysfs_nodes )
    {
      global_sysfs_nodes = cpuidle_register_governor(lpm_governor);
      if ( !global_sysfs_nodes )
      {
        global_sysfs_nodes = tracepoint_probe_register(&_tracepoint_suspend_resume, qcom_lpm_suspend_trace, 0);
        if ( !global_sysfs_nodes )
        {
          v2 = _cpuhp_setup_state(193, "qcom-cpu-lpm", 1, lpm_online_cpu, &lpm_offline_cpu, 0);
          if ( (v2 & 0x80000000) == 0 )
          {
            register_pm_notifier(&suspend_lpm_nb);
            return 0;
          }
          global_sysfs_nodes = v2;
          tracepoint_probe_unregister(&_tracepoint_suspend_resume, qcom_lpm_suspend_trace, 0);
        }
      }
      qcom_cluster_lpm_governor_deinit();
    }
    remove_global_sysfs_nodes();
  }
  return global_sysfs_nodes;
}
