__int64 zte_touch_shutdown()
{
  __int64 v0; // x19
  __int64 v1; // x2
  void (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x2

  v0 = tpd_cdev;
  printk(unk_38656, "zte_touch_shutdown", 2912);
  v2 = *(void (__fastcall **)(_QWORD))(v0 + 3544);
  if ( v2 )
  {
    /* CFI check removed */
    v2(v0);
  }
  v3 = tpd_cdev;
  v4 = printk(unk_322AA, "tpd_workqueue_deinit", v1);
  v5 = tpd_report_work_deinit(v4);
  tpd_resume_work_deinit(v5);
  v6 = tpd_cdev;
  printk(unk_322AA, "tpd_probe_work_deinit", v7);
  cancel_delayed_work_sync(v6 + 2256);
  return cancel_delayed_work_sync(v3 + 2360);
}
