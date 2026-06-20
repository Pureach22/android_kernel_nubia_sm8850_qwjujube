__int64 hdd_soc_idle_restart_lock()
{
  hdd_prevent_suspend(23);
  qdf_pm_system_wakeup();
  return 0;
}
