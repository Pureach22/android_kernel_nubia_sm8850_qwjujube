__int64 cleanup_module()
{
  debugfs_remove(qword_9690);
  remove_proc_entry("master_cdsp_stats", 0);
  printk(&unk_9E3C, "sysmon_subsystem_stats");
  remove_proc_entry("master_adsp_stats", 0);
  printk(&unk_A4CE, "sysmon_subsystem_stats");
  device_destroy(qword_9750, (unsigned int)dword_9748);
  class_destroy(qword_9750);
  cdev_del(&unk_96C8);
  return unregister_chrdev_region((unsigned int)g_subsystem_stats, 1);
}
