__int64 __fastcall thermal_pause_hp_online(unsigned int a1)
{
  _QWORD *v2; // x21
  char v3; // w8
  unsigned __int64 v4; // x19
  __int64 v5; // x22

  mutex_lock(&cpus_pause_lock);
  v2 = thermal_pause_cdev_list;
  if ( thermal_pause_cdev_list != (_UNKNOWN *)&thermal_pause_cdev_list )
  {
    v3 = a1;
    v4 = (unsigned __int64)a1 >> 6;
    v5 = 1LL << v3;
    do
    {
      if ( (v2[v4 + 2] & v5) != 0 && !v2[4] )
        queue_work_on(32, system_highpri_wq, v2 + 9);
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != &thermal_pause_cdev_list );
  }
  mutex_unlock(&cpus_pause_lock);
  return 0;
}
