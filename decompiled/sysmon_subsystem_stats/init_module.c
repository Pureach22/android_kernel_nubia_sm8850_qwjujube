__int64 init_module()
{
  __int64 dir; // x0
  void *v2; // x0

  dir = debugfs_create_dir("sysmon_subsystem_stats", 0);
  qword_9690 = dir;
  if ( !dir )
  {
    printk(&unk_A3EF, "sysmon_subsystem_stats");
    return 0;
  }
  qword_9698 = debugfs_create_file("master_adsp_stats", 292, dir, 0, &master_adsp_stats_fops);
  if ( !qword_9698 )
    printk(&unk_A434, "sysmon_subsystem_stats");
  qword_96A0 = debugfs_create_file("master_cdsp_stats", 292, qword_9690, 0, &master_cdsp_stats_fops);
  if ( !qword_96A0 )
    printk(&unk_A5C3, "sysmon_subsystem_stats");
  proc_entry_cdsp_stats = proc_create("master_cdsp_stats", 0, 0, &master_cdsp_zte_stats_fops);
  if ( proc_entry_cdsp_stats )
  {
    printk(&unk_A1FB, "sysmon_subsystem_stats");
    proc_entry_adsp_stats = proc_create("master_adsp_stats", 0, 0, &master_adsp_zte_stats_fops);
    if ( proc_entry_adsp_stats )
    {
      printk(&unk_A46F, "sysmon_subsystem_stats");
      if ( (unsigned int)alloc_chrdev_region(&g_subsystem_stats, 0, 1, "sysmon_subsystem_stats") )
      {
        printk(&unk_A496, "sysmon_subsystem_stats");
      }
      else
      {
        cdev_init(&unk_96C8, &sysmon_fops);
        qword_9728 = (__int64)&_this_module;
        if ( (unsigned int)cdev_add(&unk_96C8, g_subsystem_stats & 0xFFF00000, 1) )
        {
          printk(&unk_A077, "sysmon_subsystem_stats");
        }
        else
        {
          qword_9750 = class_create("class_subsystem_stats");
          if ( (unsigned __int64)qword_9750 >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_9A3C, "sysmon_subsystem_stats");
          }
          else
          {
            if ( (unsigned __int64)device_create() < 0xFFFFFFFFFFFFF001LL )
              return 0;
            printk(&unk_A2B4, "sysmon_subsystem_stats");
            class_destroy(qword_9750);
          }
          cdev_del(&unk_96C8);
        }
        unregister_chrdev_region((unsigned int)g_subsystem_stats, 1);
      }
      debugfs_remove(qword_9690);
      return 0;
    }
    v2 = &unk_A4F5;
  }
  else
  {
    v2 = &unk_A644;
  }
  printk(v2, "sysmon_subsystem_stats");
  return 4294967284LL;
}
