__int64 msm_show_resume_remove()
{
  tracepoint_probe_unregister(&_tracepoint_android_vh_cpuidle_psci_enter, gic_s2idle_enter, 0);
  tracepoint_probe_unregister(&_tracepoint_android_vh_cpuidle_psci_exit, gic_s2idle_exit, 0);
  unregister_syscore_ops(&gic_syscore_ops);
  return iounmap(base);
}
