__int64 ufp_mac_init()
{
  __int64 v0; // x0

  v0 = alloc_workqueue(unk_364AC, 393226, 1, "single_tap_cancel");
  qword_31430 = 0xFFFFFFFE00000LL;
  qword_31498 = v0;
  qword_31438 = (__int64)&qword_31438;
  qword_31440 = (__int64)&qword_31438;
  qword_31448 = (__int64)ufp_single_tap_work;
  init_timer_key(unk_31450, &delayed_work_timer_fn, 0x200000, 0, 0);
  dword_31428 = 0;
  wakeup_source_add(&tp_wakeup);
  init_completion(&dword_314A0);
  word_314C0 = 0;
  byte_314C2 = 0;
  if ( *(_QWORD *)(tpd_cdev + 3096) )
    ufp_tp_ops.pdev = (struct platform_device *)*(_QWORD *)(tpd_cdev + 3096);
  return 0;
}
