__int64 init_module()
{
  tracepoint_probe_register(&_tracepoint_android_vh_show_suspend_epoch_val, msm_show_suspend_epoch_val, 0);
  tracepoint_probe_register(&_tracepoint_android_vh_show_resume_epoch_val, msm_show_resume_epoch_val, 0);
  return 0;
}
