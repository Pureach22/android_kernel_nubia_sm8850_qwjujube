__int64 __fastcall hdd_sysfs_runtime_pm_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)hif_rtpm_log_debug_stats(a3, 0);
}
