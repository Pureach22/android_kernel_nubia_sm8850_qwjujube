__int64 __fastcall qcom_stats_cluster_cpuss_residency_show(__int64 a1)
{
  __int64 telemetry_counter_value; // x0

  telemetry_counter_value = get_telemetry_counter_value(**(unsigned int **)(a1 + 128));
  seq_printf(a1, "%llu\n", telemetry_counter_value);
  return 0;
}
