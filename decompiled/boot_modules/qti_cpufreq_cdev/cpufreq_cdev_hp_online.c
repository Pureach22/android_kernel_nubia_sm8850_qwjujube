__int64 __fastcall cpufreq_cdev_hp_online(int a1)
{
  _DWORD *v2; // x21

  mutex_lock(&qti_cpufreq_cdev_lock);
  v2 = qti_cpufreq_cdev_list;
  if ( qti_cpufreq_cdev_list != (_UNKNOWN *)&qti_cpufreq_cdev_list )
  {
    do
    {
      if ( v2[6] == a1 && !*((_QWORD *)v2 + 2) )
        queue_work_on(32, system_highpri_wq, v2 + 38);
      v2 = *(_DWORD **)v2;
    }
    while ( v2 != (_DWORD *)&qti_cpufreq_cdev_list );
  }
  mutex_unlock(&qti_cpufreq_cdev_lock);
  return 0;
}
