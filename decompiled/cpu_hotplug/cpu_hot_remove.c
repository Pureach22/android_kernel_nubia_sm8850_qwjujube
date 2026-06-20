__int64 cpu_hot_remove()
{
  _BYTE *v0; // x19
  _UNKNOWN **v1; // x23
  __int64 v2; // x0
  unsigned int v3; // w0
  void **v4; // x8
  _QWORD *v5; // x9

  if ( cpu_hp_online )
  {
    _cpuhp_remove_state();
    cpu_hp_online = 0;
  }
  mutex_lock(&cpu_hot_lock);
  v0 = cpu_hot_cdev_list;
  if ( cpu_hot_cdev_list != (_UNKNOWN *)&cpu_hot_cdev_list )
  {
    do
    {
      v1 = *(_UNKNOWN ***)v0;
      if ( *((_QWORD *)v0 + 3) )
      {
        thermal_cooling_device_unregister();
        if ( v0[20] == 1 )
        {
          v2 = *((unsigned int *)v0 + 4);
          v0[20] = 0;
          v3 = add_cpu(v2);
          if ( v3 )
            printk(&unk_682F, *((unsigned int *)v0 + 4), v3);
        }
      }
      v4 = *((void ***)v0 + 1);
      if ( *v4 == v0 && (v5 = *(_QWORD **)v0, *(_BYTE **)(*(_QWORD *)v0 + 8LL) == v0) )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *(_QWORD *)v0 = 0xDEAD000000000100LL;
      *((_QWORD *)v0 + 1) = 0xDEAD000000000122LL;
      v0 = v1;
    }
    while ( v1 != &cpu_hot_cdev_list );
  }
  return mutex_unlock(&cpu_hot_lock);
}
