__int64 __fastcall trace_raw_output_sched_pipeline_tasks(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "type=%d index=%d pid=%d comm=%s demand=%d coloc_demand=%d pipeline_cpu=%d low_latency=0x%x nr_pipeline=%d special_"
      "pid=%d util_thres=%u total_util=%u pipeline_pin=%d event_windows=%d pipeline_activity_cnt=%u lst=%d gold_demand=%l"
      "lu prime_demand=%llu config=%d t0_bias=%d\n",
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 32),
      (const char *)(v1 + 16),
      *(_DWORD *)(v1 + 36),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(unsigned __int8 *)(v1 + 76),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 68),
      *(unsigned __int8 *)(v1 + 77),
      *(_QWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 96),
      *(unsigned __int8 *)(v1 + 100));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
