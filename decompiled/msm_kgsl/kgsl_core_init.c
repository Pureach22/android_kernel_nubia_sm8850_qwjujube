__int64 kgsl_core_init()
{
  int v0; // w0
  int v1; // w0
  unsigned __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x0
  void *v6; // x0
  void *v7; // x0

  printk(&unk_13A74E);
  v0 = alloc_chrdev_region(&dword_3A448, 0, 1, "kgsl");
  if ( v0 < 0 )
  {
    LODWORD(v2) = v0;
    printk(&unk_146355);
    goto LABEL_8;
  }
  cdev_init(&kgsl_driver, &kgsl_fops);
  qword_3A420 = (__int64)&_this_module;
  qword_3A428 = (__int64)&kgsl_fops;
  v1 = cdev_add(&kgsl_driver, dword_3A448 & 0xFFF00000, 1);
  if ( v1 )
  {
    LODWORD(v2) = v1;
    printk(&unk_1406BF);
    goto LABEL_8;
  }
  v2 = class_create("kgsl");
  qword_3A450 = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    v6 = &unk_1406F2;
LABEL_14:
    printk(v6);
    goto LABEL_8;
  }
  qword_3A770 = v2;
  dev_set_name(&unk_3A458, "kgsl");
  v3 = device_register(&unk_3A458);
  if ( v3 )
  {
    LODWORD(v2) = v3;
    put_device(&unk_3A458);
    v6 = &unk_146A5B;
    goto LABEL_14;
  }
  qword_3A6D8 = (__int64)&kgsl_core_init_dma_mask;
  qword_3A6F8 = (__int64)&kgsl_core_init_dma_parms;
  kgsl_core_init_dma_parms = -1;
  qword_3A6D0 = 0;
  qword_3A7E8 = kobject_create_and_add("pagetables", &unk_3A458);
  qword_3A7F0 = kobject_create_and_add("proc", &unk_3A458);
  kgsl_core_debugfs_init();
  kgsl_sharedmem_init_sysfs();
  kgsl_register_shmem_callback();
  qword_3A800 = (__int64)&qword_3A800;
  qword_3A808 = (__int64)&qword_3A800;
  qword_3A828 = (__int64)&qword_3A828;
  qword_3A830 = (__int64)&qword_3A828;
  qword_3A810 = (__int64)&qword_3A810;
  qword_3A818 = (__int64)&qword_3A810;
  qword_3A900 = alloc_workqueue("kgsl-workqueue", 74, 0);
  if ( !qword_3A900 )
  {
    v7 = &unk_13A76F;
LABEL_17:
    printk(v7);
    LODWORD(v2) = -12;
    goto LABEL_8;
  }
  qword_3A908 = alloc_workqueue("kgsl-lockless-work", 10, 0);
  if ( !qword_3A908 )
  {
    v7 = &unk_141AC6;
    goto LABEL_17;
  }
  v4 = kgsl_eventlog_init();
  kgsl_events_init(v4);
  LODWORD(v2) = kgsl_drawobjs_cache_init();
  if ( !(_DWORD)v2 )
  {
    memfree = _kmalloc_large_noprof(20480, 3520);
    sysstats_register_kgsl_stats_cb(kgsl_get_stats);
    printk(&unk_144927);
    kgsl_pwrctrl_set_max_level_fp = kgsl_pwrctrl_set_max_level;
    LODWORD(v2) = 0;
    kgsl_pwrctrl_get_max_level_fp = kgsl_pwrctrl_get_max_level;
    kgsl_pwrctrl_set_min_level_fp = kgsl_pwrctrl_set_min_level;
    kgsl_pwrctrl_get_min_level_fp = kgsl_pwrctrl_get_min_level;
    kgsl_pwrctrl_get_loading_fp = kgsl_pwrctrl_get_gpu_loading;
    kgsl_gpu_num_freqs_fp = kgsl_gpu_num_freqs;
    return (unsigned int)v2;
  }
LABEL_8:
  kgsl_core_exit();
  return (unsigned int)v2;
}
