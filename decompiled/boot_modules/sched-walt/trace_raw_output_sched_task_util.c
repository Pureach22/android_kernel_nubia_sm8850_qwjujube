__int64 __fastcall trace_raw_output_sched_task_util(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s util=%lu prev_cpu=%d candidates=%#lx best_energy_cpu=%d sync=%d need_idle=%d fastpath=%d placement_"
      "boost=%d latency=%llu stune_boosted=%d is_rtg=%d rtg_skip_min=%d start_cpu=%d unfilter=%u affinity=%lx task_boost="
      "%d low_latency=%d iowaited=%d load_boost=%d sync_state=%d pipeline_cpu=%d yield_cnt=%d\n",
      *(_DWORD *)(v1 + 8),
      (const char *)(v1 + 12),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 52),
      *(unsigned __int8 *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(_QWORD *)(v1 + 80),
      *(unsigned __int8 *)(v1 + 88),
      *(unsigned __int8 *)(v1 + 89),
      *(unsigned __int8 *)(v1 + 90),
      *(_DWORD *)(v1 + 92),
      *(_DWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 104),
      *(_DWORD *)(v1 + 112),
      *(unsigned __int8 *)(v1 + 116),
      *(unsigned __int8 *)(v1 + 117),
      *(_DWORD *)(v1 + 120),
      *(unsigned __int8 *)(v1 + 124),
      *(_DWORD *)(v1 + 128),
      *(_DWORD *)(v1 + 132));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
