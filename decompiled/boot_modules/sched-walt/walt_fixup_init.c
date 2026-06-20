__int64 walt_fixup_init()
{
  android_rvh_probe_register(&_tracepoint_android_rvh_show_max_freq, android_rvh_show_max_freq, 0);
  android_rvh_probe_register(&_tracepoint_android_rvh_cpu_capacity_show, android_rvh_cpu_capacity_show, 0);
  return android_rvh_probe_register(&_tracepoint_android_rvh_before_do_sched_yield, walt_do_sched_yield_before, 0);
}
