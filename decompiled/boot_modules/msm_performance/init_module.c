__int64 init_module()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned __int64 v7; // x0
  __int64 v8; // x19
  void *v10; // x0
  void *v11; // x0
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  char v15; // w10
  int v16; // w20
  unsigned __int64 v17; // x10
  unsigned __int64 v18; // x10
  bool v19; // cf
  __int64 v20; // x21
  char v21; // w8
  char v22; // w27
  __int64 v23; // x8
  __int64 v24; // x0
  char v25; // w8
  unsigned __int64 v26; // x8
  _QWORD *v27; // x9
  unsigned __int64 v28; // x19
  unsigned int *v29; // x24
  int v30; // w0
  __int64 v31; // x8
  unsigned int *v32; // x23
  int v33; // w0
  int v34; // w22
  int v35; // w22
  _QWORD *v36; // x8
  void *v37; // x0
  __int64 v38; // x19
  char v39; // w13
  int v40; // w9
  unsigned __int64 v41; // x13
  unsigned __int64 v42; // x13
  __int64 v43; // x0

  v0 = kset_create_and_add("msm_performance", 0, kernel_kobj);
  msm_perf_kset = v0;
  if ( !v0 )
    return 4294967284LL;
  v1 = kobject_create_and_add("parameters", v0 + 24);
  param_kobj = v1;
  if ( v1 )
  {
    if ( !(unsigned int)sysfs_create_group(v1, &param_attr_group) )
      goto LABEL_4;
    v10 = &unk_B9C0;
  }
  else
  {
    v10 = &unk_BA6A;
  }
  printk(v10, v2, v3);
LABEL_4:
  v4 = kobject_create_and_add("events", msm_perf_kset + 24);
  events_kobj = v4;
  if ( !v4 )
  {
    v11 = &unk_BBE0;
LABEL_15:
    printk(v11, v5, v6);
    goto LABEL_16;
  }
  if ( (unsigned int)sysfs_create_group(v4, &events_attr_group) )
  {
    v11 = &unk_B9C0;
    goto LABEL_15;
  }
  events_group = 0;
  v7 = kthread_create_on_node(events_notify_userspace, 0, 0xFFFFFFFFLL, "msm_perf:events_notify");
  v8 = v7;
  if ( v7 < 0xFFFFFFFFFFFFF001LL )
  {
    wake_up_process(v7);
    events_notify_thread = v8;
    byte_B9AD = 1;
  }
  else
  {
    events_notify_thread = v7;
  }
LABEL_16:
  v12 = kobject_create_and_add("notify", msm_perf_kset + 24);
  notify_kobj = v12;
  if ( v12 )
  {
    if ( !(unsigned int)sysfs_create_group(v12, &notify_attr_group) )
      goto LABEL_18;
    kobject_put(notify_kobj);
    v37 = &unk_B9C0;
  }
  else
  {
    v37 = &unk_BA90;
  }
  printk(v37, v13, v14);
LABEL_18:
  v15 = 0;
  v16 = 0;
  do
  {
    v17 = _cpu_possible_mask & (unsigned __int64)(-1LL << v15);
    if ( !v17 )
      break;
    ++v16;
    v18 = __clz(__rbit64(v17));
    v19 = v18 >= 0x1F;
    v15 = v18 + 1;
  }
  while ( !v19 );
  pmu_events = _kmalloc_cache_noprof(qcom_pmu_event_supported, 3520, 16);
  if ( pmu_events )
  {
    v20 = 0;
    v21 = 1;
    _ReadStatusReg(SP_EL0);
    do
    {
      v22 = v21;
      if ( v16 < 0 )
      {
        v24 = pmu_events;
        *(_QWORD *)(pmu_events + 8 * v20) = 0;
LABEL_44:
        v38 = 8 * v20;
        do
        {
          kfree(*(_QWORD *)(v24 + v38));
          v24 = pmu_events;
          *(_QWORD *)(pmu_events + v38) = 0;
          v38 -= 8;
        }
        while ( v38 != -8 );
        kfree(v24);
        pmu_events = 0;
        goto LABEL_47;
      }
      v23 = _kmalloc_noprof(32LL * v16, 3520);
      v24 = pmu_events;
      *(_QWORD *)(pmu_events + 8 * v20) = v23;
      if ( !v23 )
        goto LABEL_44;
      v21 = 0;
      v20 = 1;
    }
    while ( (v22 & 1) != 0 );
    v25 = 0;
    do
    {
      v26 = (unsigned int)(-1LL << v25) & _cpu_possible_mask;
      if ( !(_DWORD)v26 )
        break;
      v27 = (_QWORD *)pmu_events;
      v28 = __clz(__rbit64(v26));
      *(_DWORD *)(*(_QWORD *)pmu_events + 32 * v28) = 8;
      v29 = (unsigned int *)(*v27 + 32 * v28);
      v30 = qcom_pmu_event_supported(*v29, (unsigned int)v28);
      if ( v30 )
      {
        v34 = v30;
        printk(&unk_BD2F, "set_event", *v29);
        if ( v34 < 0 )
          break;
      }
      v31 = pmu_events;
      *(_DWORD *)(*(_QWORD *)(pmu_events + 8) + 32 * v28) = 17;
      v32 = (unsigned int *)(*(_QWORD *)(v31 + 8) + 32 * v28);
      v33 = qcom_pmu_event_supported(*v32, (unsigned int)v28);
      if ( v33 )
      {
        v35 = v33;
        printk(&unk_BD2F, "set_event", *v32);
        if ( v35 < 0 )
        {
          if ( ((_cpu_possible_mask >> v28) & 1) != 0 )
          {
            v36 = (_QWORD *)pmu_events;
            *(_QWORD *)(*(_QWORD *)pmu_events + 32 * v28 + 8) = 0;
            *(_QWORD *)(*v36 + 32 * v28 + 16) = 0;
            *(_QWORD *)(*v36 + 32 * v28 + 24) = 0;
            *(_QWORD *)(v36[1] + 32 * v28 + 8) = 0;
            *(_QWORD *)(v36[1] + 32 * v28 + 16) = 0;
            *(_QWORD *)(v36[1] + 32 * v28 + 24) = 0;
          }
          break;
        }
      }
      if ( *(_QWORD *)((char *)&cpu_scale + _per_cpu_offset[v28]) < (unsigned __int64)min_cpu_capacity )
        min_cpu_capacity = *(_QWORD *)((char *)&cpu_scale + _per_cpu_offset[v28]);
      v25 = v28 + 1;
    }
    while ( v28 < 0x1F );
  }
LABEL_47:
  cpus_read_lock();
  v39 = 0;
  v40 = _cpu_possible_mask;
  do
  {
    v41 = (unsigned int)(-1LL << v39) & v40;
    if ( !(_DWORD)v41 )
      break;
    v42 = __clz(__rbit64(v41));
    if ( ((_cpu_online_mask >> v42) & 1) == 0 )
    {
      cpu_is_hp[_per_cpu_offset[v42]] = 1;
      v40 = _cpu_possible_mask;
    }
    v19 = v42 >= 0x1F;
    v39 = v42 + 1;
  }
  while ( !v19 );
  v43 = _cpuhp_setup_state_cpuslocked(193, "msm_performance_cpu_hotplug", 0, hotplug_notify_up, hotplug_notify_down, 0);
  cpus_read_unlock(v43);
  return 0;
}
