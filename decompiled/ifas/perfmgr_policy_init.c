__int64 perfmgr_policy_init()
{
  __int64 v0; // x8
  __int64 result; // x0
  __int64 dev_root; // x0
  __int64 v3; // x0
  __int64 inited; // x0

  cpufreq_wq = alloc_workqueue("cpufreq_wq", 16, 0);
  v0 = alloc_workqueue("gpufreq_wq", 16, 0);
  gpufreq_wq = v0;
  result = 4294967282LL;
  if ( cpufreq_wq && v0 )
  {
    dev_root = bus_get_dev_root(&cpu_subsys);
    perfmgr_policy_kobj = kobject_create_and_add("perfmgr", dev_root);
    v3 = ifas_sysfs_init();
    cpu_ctrl_init(v3);
    maxfreq_release_work = 0xFFFFFFFE00000LL;
    qword_D4B8 = (__int64)&qword_D4B8;
    qword_D4C0 = (__int64)&qword_D4B8;
    qword_D4C8 = (__int64)do_maxfreq_release_work;
    init_timer_key(&unk_D4D0, &delayed_work_timer_fn, 0x200000, 0, 0);
    gpu_maxfreq_release_work = 0xFFFFFFFE00000LL;
    qword_D530 = (__int64)&qword_D530;
    qword_D538 = (__int64)&qword_D530;
    qword_D540 = (__int64)do_gpu_maxfreq_release_work;
    inited = init_timer_key(&unk_D548, &delayed_work_timer_fn, 0x200000, 0, 0);
    gpu_ctrl_init(inited);
    if ( ifas_log_enable )
      printk(&unk_F3CB, "perfmgr_policy_init");
    return 0;
  }
  return result;
}
