__int64 init_module()
{
  unsigned int v0; // w19
  unsigned int v1; // w0

  dword_65CC = 5;
  v0 = tracepoint_probe_register(&_tracepoint_android_vh_check_uninterruptible_tasks, qcom_before_check_tasks, 0);
  if ( !v0 )
  {
    v1 = tracepoint_probe_register(&_tracepoint_android_vh_check_uninterruptible_tasks_dn, qcom_check_tasks_done, 0);
    if ( v1 )
    {
      v0 = v1;
      tracepoint_probe_unregister(&_tracepoint_android_vh_check_uninterruptible_tasks, qcom_before_check_tasks, 0);
    }
    else
    {
      qword_65D8 = register_sysctl_sz("hung_task_enh", &hung_task_table, 5);
      if ( qword_65D8 )
      {
        return 0;
      }
      else
      {
        tracepoint_probe_unregister(&_tracepoint_android_vh_check_uninterruptible_tasks, qcom_before_check_tasks, 0);
        tracepoint_probe_unregister(&_tracepoint_android_vh_check_uninterruptible_tasks_dn, qcom_check_tasks_done, 0);
        return (unsigned int)-12;
      }
    }
  }
  return v0;
}
