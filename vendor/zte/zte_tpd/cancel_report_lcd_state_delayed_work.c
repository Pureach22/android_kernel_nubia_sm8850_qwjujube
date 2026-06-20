__int64 cancel_report_lcd_state_delayed_work(void)
{
  return cancel_delayed_work_sync(tpd_cdev + 2528);
}
