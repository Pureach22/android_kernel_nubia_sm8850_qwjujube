void *rmnet_shs_exit()
{
  rmnet_shs_freq_exit();
  rmnet_shs_ll_deinit();
  byte_19491 = 0;
  unregister_oom_notifier(&rmnet_oom_nb);
  hrtimer_cancel(&rmnet_shs_cfg);
  hrtimer_cancel(&unk_18F70);
  hrtimer_cancel(&unk_18FB0);
  wakeup_source_unregister(qword_19480);
  return memset(&rmnet_shs_cfg, 0, 0x578u);
}
