__int64 cleanup_module()
{
  unregister_sysctl_table(qword_65D8);
  tracepoint_probe_unregister(&_tracepoint_android_vh_check_uninterruptible_tasks, qcom_before_check_tasks, 0);
  return tracepoint_probe_unregister(&_tracepoint_android_vh_check_uninterruptible_tasks_dn, qcom_check_tasks_done, 0);
}
