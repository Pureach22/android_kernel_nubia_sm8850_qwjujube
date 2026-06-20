__int64 __fastcall cpufreq_cdev_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 next_available_child; // x0
  const char **v4; // x21
  __int64 v5; // x24
  char v6; // w8
  bool v7; // zf
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x25
  __int64 cpu_device; // x0
  __int64 v12; // x0
  __int64 v13; // x24
  void *v14; // x2
  __int64 result; // x0
  _QWORD v16[7]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v17 = 0;
  memset(v16, 0, sizeof(v16));
  mutex_lock(&qti_cpufreq_cdev_lock);
  next_available_child = of_get_next_available_child(v2, 0);
  if ( next_available_child )
  {
    v4 = (const char **)next_available_child;
    do
    {
      of_phandle_iterator_init(v16, v4, "qcom,cpus", 0, 0);
LABEL_6:
      while ( !(unsigned int)of_phandle_iterator_next(v16) )
      {
        v5 = v17;
        v6 = 0;
        while ( 1 )
        {
          v8 = (unsigned int)(-1LL << v6) & _cpu_possible_mask;
          v7 = (_DWORD)v8 == 0;
          v9 = __clz(__rbit64(v8));
          v10 = v7 ? 32LL : v9;
          if ( (unsigned int)v10 > 0x1F )
            break;
          cpu_device = get_cpu_device((unsigned int)v10);
          if ( cpu_device && *(_QWORD *)(cpu_device + 744) == v5 )
          {
            v12 = devm_kmalloc(a1 + 16, 184, 3520);
            if ( !v12 )
            {
              mutex_unlock(&qti_cpufreq_cdev_lock);
              result = 4294967284LL;
              goto LABEL_22;
            }
            *(_DWORD *)(v12 + 24) = v10;
            v13 = v12;
            snprintf((char *)(v12 + 120), 0x14u, *v4);
            *(_QWORD *)(v13 + 152) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v13 + 160) = v13 + 160;
            *(_QWORD *)(v13 + 168) = v13 + 160;
            v14 = qti_cpufreq_cdev_list;
            *(_QWORD *)(v13 + 176) = cpufreq_cdev_register;
            if ( v14 == (void *)v13 || *(_UNKNOWN ***)((char *)&off_8 + (_QWORD)v14) != &qti_cpufreq_cdev_list )
            {
              _list_add_valid_or_report(v13, &qti_cpufreq_cdev_list);
            }
            else
            {
              *(_UNKNOWN **)((char *)&off_8 + (_QWORD)v14) = (_UNKNOWN *)v13;
              *(_QWORD *)v13 = v14;
              *(_QWORD *)(v13 + 8) = &qti_cpufreq_cdev_list;
              qti_cpufreq_cdev_list = (_UNKNOWN *)v13;
            }
            goto LABEL_4;
          }
          v6 = v10 + 1;
          if ( v10 > 0x1E )
            goto LABEL_6;
        }
      }
LABEL_4:
      v4 = (const char **)of_get_next_available_child(v2, v4);
    }
    while ( v4 );
  }
  mutex_unlock(&qti_cpufreq_cdev_lock);
  result = _cpuhp_setup_state(193, "thermal-cpu/cdev:online", 1, cpufreq_cdev_hp_online, 0, 0);
  if ( (result & 0x80000000) == 0 )
  {
    cpu_hp_online = result;
    result = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
