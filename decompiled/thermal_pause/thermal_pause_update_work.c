__int64 __fastcall thermal_pause_update_work(__int64 a1)
{
  _QWORD *v2; // x21
  int v3; // w25
  int v4; // w26
  int v5; // w8
  _QWORD *v6; // x8
  __int64 v7; // x27
  char v8; // w8
  __int64 v9; // x27
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x28
  char v12; // w8
  __int64 v13; // x20
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x28
  bool v16; // vf
  __int64 result; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = (_QWORD *)(a1 - 104);
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&cpus_pause_lock);
  v3 = 0;
  v4 = 5;
  do
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(a1 - 76);
      if ( v5 == *(_DWORD *)(a1 - 80) )
      {
        if ( v3 < 0 )
          goto LABEL_31;
        goto LABEL_4;
      }
      if ( !v5 )
        break;
      v18[0] = *(_QWORD *)(a1 - 88);
      printk(&unk_6B34, "thermal_pause", "thermal_pause_work", nr_cpu_ids, a1 - 88);
      mutex_unlock(&cpus_pause_lock);
      v3 = walt_pause_cpus(v18, 2);
      mutex_lock(&cpus_pause_lock);
      if ( v3 )
      {
        printk(&unk_6B0B, "thermal_pause", "thermal_pause_work", nr_cpu_ids, a1 - 88);
        if ( v3 < 0 )
          goto LABEL_29;
      }
      else
      {
        v8 = 0;
        v9 = *(_DWORD *)(a1 - 88) & (unsigned int)~(_DWORD)cpus_in_max_cooling_level;
        do
        {
          v10 = v9 & (-1LL << v8);
          if ( !v10 )
            break;
          v11 = __clz(__rbit64(v10));
          blocking_notifier_call_chain(&thermal_pause_notifier, 1, v11);
          v8 = v11 + 1;
        }
        while ( v11 < 0x1F );
        cpus_in_max_cooling_level |= *(_QWORD *)(a1 - 88);
      }
      v5 = 1;
      *(_DWORD *)(a1 - 80) = 1;
LABEL_4:
      v4 = 5;
      if ( *(_DWORD *)(a1 - 76) == v5 )
        goto LABEL_31;
    }
    v18[0] = *(_QWORD *)(a1 - 88);
    printk(&unk_6A58, "thermal_pause", "thermal_resume_work", nr_cpu_ids, v18);
    mutex_unlock(&cpus_pause_lock);
    v3 = walt_resume_cpus(v18, 2);
    mutex_lock(&cpus_pause_lock);
    if ( !v3 )
    {
      v6 = thermal_pause_cdev_list;
      if ( thermal_pause_cdev_list == (_UNKNOWN *)&thermal_pause_cdev_list )
      {
        v7 = 0;
      }
      else
      {
        v7 = 0;
        do
        {
          if ( v6 != v2 && *((_DWORD *)v6 + 6) )
            v7 |= v6[2];
          v6 = (_QWORD *)*v6;
        }
        while ( v6 != &thermal_pause_cdev_list );
      }
      v12 = 0;
      v13 = ~(_DWORD)v7 & (unsigned int)cpus_in_max_cooling_level;
      do
      {
        v14 = v13 & (-1LL << v12);
        if ( !v14 )
          break;
        v15 = __clz(__rbit64(v14));
        blocking_notifier_call_chain(&thermal_pause_notifier, 0, v15);
        v12 = v15 + 1;
      }
      while ( v15 < 0x1F );
      cpus_in_max_cooling_level = v7;
LABEL_25:
      v5 = 0;
      *(_DWORD *)(a1 - 80) = 0;
      goto LABEL_4;
    }
    printk(&unk_6A9D, "thermal_pause", "thermal_resume_work", nr_cpu_ids, a1 - 88);
    if ( (v3 & 0x80000000) == 0 )
      goto LABEL_25;
LABEL_29:
    v16 = __OFSUB__(v4--, 1);
  }
  while ( v4 < 0 == v16 );
LABEL_31:
  result = mutex_unlock(&cpus_pause_lock);
  _ReadStatusReg(SP_EL0);
  return result;
}
