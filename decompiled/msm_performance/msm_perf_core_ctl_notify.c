__int64 msm_perf_core_ctl_notify()
{
  if ( ++msm_perf_core_ctl_notify_i == 25 )
  {
    top_load_0 = 0;
    curr_cap_0 = 0;
    top_load_1 = 0;
    curr_cap_1 = 0;
    top_load_2 = 0;
    curr_cap_2 = 0;
    msm_perf_core_ctl_notify_i = 0;
    queue_work_on(32, system_wq, &msm_perf_core_ctl_notify_sysfs_notify_work);
  }
  return 1;
}
