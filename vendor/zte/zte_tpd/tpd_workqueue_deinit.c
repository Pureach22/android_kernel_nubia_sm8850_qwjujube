__int64 __fastcall tpd_workqueue_deinit(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x2

  v3 = tpd_cdev;
  v4 = printk(unk_322AA, "tpd_workqueue_deinit", a3);
  v5 = tpd_report_work_deinit(v4);
  tpd_resume_work_deinit(v5);
  v6 = tpd_cdev;
  printk(unk_322AA, "tpd_probe_work_deinit", v7);
  cancel_delayed_work_sync(v6 + 2256);
  return cancel_delayed_work_sync(v3 + 2360);
}
