__int64 __fastcall qcom_cpuss_sleep_stats_remove(__int64 a1)
{
  return debugfs_remove(*(_QWORD *)(a1 + 168));
}
