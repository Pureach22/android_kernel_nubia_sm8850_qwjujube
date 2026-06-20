__int64 __fastcall qcom_stats_core_count_show(__int64 a1)
{
  int telemetry_counter_value; // w0

  telemetry_counter_value = get_telemetry_counter_value(**(unsigned int **)(a1 + 128));
  seq_printf(a1, "%u\n", telemetry_counter_value);
  return 0;
}
