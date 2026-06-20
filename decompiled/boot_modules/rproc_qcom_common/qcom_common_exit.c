// Alternative name is 'cleanup_module'
__int64 qcom_common_exit()
{
  sysfs_remove_file_ns(sysfs_kobject, &both_coredumps_attr, 0);
  sysfs_remove_file_ns(sysfs_kobject, &shutdown_requested_attr, 0);
  kobject_put(sysfs_kobject);
  return tracepoint_probe_unregister(&_tracepoint_android_vh_rproc_recovery, qcom_check_ssr_status, 0);
}
