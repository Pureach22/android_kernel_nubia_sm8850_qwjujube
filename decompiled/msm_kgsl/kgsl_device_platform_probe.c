__int64 __fastcall kgsl_device_platform_probe(unsigned __int64 *a1)
{
  unsigned __int64 v2; // x23
  unsigned __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 v5; // x2
  __int64 v6; // x0
  unsigned int v7; // w20
  unsigned __int64 worker; // x0
  __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v12; // x8
  void (__fastcall *v13)(_QWORD); // x8

  v2 = a1[1396];
  mutex_lock(&unk_3A878);
  if ( off_3A7F8 )
  {
    mutex_unlock(&unk_3A878);
    printk(&unk_145C5E);
    return (unsigned int)-19;
  }
  off_3A7F8 = a1;
  mutex_unlock(&unk_3A878);
  v3 = device_create(qword_3A450, a1[1396] + 16, dword_3A448 & 0xFFF00000, a1, a1[1]);
  *a1 = v3;
  if ( v3 > 0xFFFFFFFFFFFFF000LL )
  {
    mutex_lock(&unk_3A878);
    off_3A7F8 = nullptr;
    mutex_unlock(&unk_3A878);
    v7 = *(_DWORD *)a1;
    printk(&unk_13F592);
    if ( v7 )
      return v7;
  }
  else
  {
    *(_QWORD *)(v3 + 640) = &register_device_dma_mask;
    *(_QWORD *)(*a1 + 672) = &register_device_dma_parms;
    if ( (a1[13] & 8) != 0 )
      *(_BYTE *)(*a1 + 844) |= 0x20u;
    v4 = *(_DWORD **)(*a1 + 672);
    if ( v4 )
      *v4 = -1;
    else
      __break(0x800u);
    v5 = kernel_kobj;
    *(_QWORD *)(*a1 + 632) = 0;
    if ( (unsigned int)kobject_init_and_add(a1 + 1624, kgsl_gpu_sysfs_ktype, v5, "gpu") )
      __break(0x800u);
  }
  v6 = kgsl_pwrctrl_init(a1);
  v7 = v6;
  if ( (_DWORD)v6 )
    goto LABEL_15;
  worker = kthread_create_worker(v6, "kgsl-events");
  v7 = worker;
  a1[1622] = worker;
  if ( worker >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*a1, "Failed to create events worker ret=%d\n", worker);
    goto LABEL_12;
  }
  v9 = sched_set_fifo(*(_QWORD *)(worker + 40));
  v7 = kgsl_reclaim_init(v9);
  if ( v7 )
  {
LABEL_12:
    v10 = a1[1622];
    if ( v10 <= 0xFFFFFFFFFFFFF000LL )
      kthread_destroy_worker(v10);
    kgsl_pwrctrl_close(a1);
LABEL_15:
    if ( (*((_BYTE *)a1 + 13052) & 1) != 0 )
      kobject_put(a1 + 1624);
    mutex_lock(&unk_3A878);
    if ( off_3A7F8 == (_UNKNOWN *)a1 )
    {
      device_destroy(qword_3A450, dword_3A448 & 0xFFF00000);
      off_3A7F8 = nullptr;
    }
    mutex_unlock(&unk_3A878);
    return v7;
  }
  a1[1401] = 0;
  *((_DWORD *)a1 + 2770) = 0;
  a1[1672] = 0x1000000400000000LL;
  a1[1673] = 0;
  a1[1674] = 0;
  *((_DWORD *)a1 + 3350) = 0;
  kgsl_device_debugfs_init(a1);
  dma_set_coherent_mask(v2 + 16, -1);
  kgsl_device_events_probe(a1);
  kgsl_pwrctrl_init_sysfs(a1);
  v12 = a1[11];
  if ( v12 )
  {
    v13 = *(void (__fastcall **)(_QWORD))(v12 + 112);
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != -919125270 )
        __break(0x8228u);
      v13(a1 + 7);
    }
  }
  init_timer_key(a1 + 1755, kgsl_work_period_timer, 0, 0, 0);
  v7 = 0;
  a1[1761] = 0xFFFFFFFE00000LL;
  *((_DWORD *)a1 + 3520) = 0;
  a1[1762] = (unsigned __int64)(a1 + 1762);
  a1[1763] = (unsigned __int64)(a1 + 1762);
  a1[1764] = (unsigned __int64)log_gpu_work_events;
  return v7;
}
