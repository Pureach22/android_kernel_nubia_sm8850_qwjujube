__int64 __fastcall wlan_hdd_pld_idle_shutdown(__int64 a1)
{
  hdd_prevent_suspend(24);
  qdf_pm_system_wakeup();
  LODWORD(a1) = hdd_psoc_idle_shutdown(a1);
  hdd_allow_suspend(24);
  return (unsigned int)a1;
}
