__int64 cpufreq_cdev_remove()
{
  _UNKNOWN **i; // x20
  void *v1; // x0
  unsigned __int64 v2; // x8

  mutex_lock(&qti_cpufreq_cdev_lock);
  if ( cpu_hp_online )
  {
    _cpuhp_remove_state();
    cpu_hp_online = 0;
  }
  for ( i = (_UNKNOWN **)qti_cpufreq_cdev_list; i != &qti_cpufreq_cdev_list; i = (_UNKNOWN **)*i )
  {
    if ( i[2] )
    {
      thermal_cooling_device_unregister();
      v2 = (unsigned __int64)i[13];
      if ( v2 )
      {
        if ( v2 <= 0xFFFFFFFFFFFFF000LL )
          freq_qos_remove_request(i + 7);
      }
      v1 = i[18];
      i[2] = nullptr;
      cpufreq_cpu_put(v1);
      kfree(i[6]);
    }
  }
  return mutex_unlock(&qti_cpufreq_cdev_lock);
}
