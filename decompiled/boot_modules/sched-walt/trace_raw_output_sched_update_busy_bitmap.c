__int64 __fastcall trace_raw_output_sched_update_busy_bitmap(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s on_rq=%d wc=%llu ms=%llu rq_cpu=%d pipeline_cpu=%d event=%s busy_bits=0x%x period_contrib_run=%u ne"
      "xt_ms_boundary=%llu no_boost_reason=%d lrb_pipeline_start_time=%llu\n",
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 28),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      task_event_names[*(unsigned int *)(v1 + 56)],
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
