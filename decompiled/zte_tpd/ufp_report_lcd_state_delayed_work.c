__int64 ufp_report_lcd_state_delayed_work()
{
  __int64 v0; // x20
  __int64 v1; // x19
  __int64 v2; // x0

  v0 = tpd_cdev;
  v1 = *(_QWORD *)(tpd_cdev + 1200);
  v2 = _msecs_to_jiffies();
  return mod_delayed_work_on(32, v1, v0 + 2528, v2);
}
