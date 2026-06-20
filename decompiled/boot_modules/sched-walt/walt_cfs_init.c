__int64 walt_cfs_init()
{
  android_rvh_probe_register(&_tracepoint_android_rvh_select_task_rq_fair, walt_select_task_rq_fair, 0);
  tracepoint_probe_register(&_tracepoint_android_vh_binder_set_priority, binder_set_priority_hook, 0);
  tracepoint_probe_register(&_tracepoint_android_vh_binder_restore_priority, binder_restore_priority_hook, 0);
  android_rvh_probe_register(&_tracepoint_android_rvh_check_preempt_wakeup_fair, walt_cfs_check_preempt_wakeup_fair, 0);
  return android_rvh_probe_register(&_tracepoint_android_rvh_replace_next_task_fair, walt_cfs_replace_next_task_fair, 0);
}
