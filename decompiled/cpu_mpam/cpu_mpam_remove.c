__int64 cpu_mpam_remove()
{
  configfs_unregister_subsystem(&cpu_mpam_subsys);
  return tracepoint_probe_unregister(&_tracepoint_android_vh_mpam_set, cpu_mpam_switch_task, 0);
}
