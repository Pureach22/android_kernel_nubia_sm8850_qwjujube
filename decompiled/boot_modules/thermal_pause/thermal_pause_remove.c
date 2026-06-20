__int64 thermal_pause_remove()
{
  _DWORD *v0; // x19
  _UNKNOWN **v1; // x23
  __int64 v2; // x1
  void **v3; // x8
  _QWORD *v4; // x9

  if ( cpu_hp_online )
  {
    _cpuhp_remove_state();
    cpu_hp_online = 0;
  }
  mutex_lock(&cpus_pause_lock);
  v0 = thermal_pause_cdev_list;
  if ( thermal_pause_cdev_list != (_UNKNOWN *)&thermal_pause_cdev_list )
  {
    do
    {
      v1 = *(_UNKNOWN ***)v0;
      if ( v0[6] )
      {
        v2 = system_highpri_wq;
        v0[7] = 0;
        queue_work_on(32, v2, v0 + 26);
      }
      if ( *((_QWORD *)v0 + 4) )
        thermal_cooling_device_unregister();
      v3 = *((void ***)v0 + 1);
      if ( *v3 == v0 && (v4 = *(_QWORD **)v0, *(_DWORD **)(*(_QWORD *)v0 + 8LL) == v0) )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *(_QWORD *)v0 = 0xDEAD000000000100LL;
      *((_QWORD *)v0 + 1) = 0xDEAD000000000122LL;
      v0 = v1;
    }
    while ( v1 != &thermal_pause_cdev_list );
  }
  return mutex_unlock(&cpus_pause_lock);
}
