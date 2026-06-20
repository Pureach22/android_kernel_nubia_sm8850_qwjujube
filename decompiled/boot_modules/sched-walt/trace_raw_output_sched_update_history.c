__int64 __fastcall trace_raw_output_sched_update_history(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s runtime=%u samples=%d event=%s demand=%u (hist: %u %u %u %u %u) (hist_util: %u %u %u %u %u) coloc_d"
      "emand=%u pred_demand_scaled=%u cpu=%d nr_big=%u trailblazer_demand=%u high_util_history=%u uclamp_min=%llu uclamp_max=%llu\n",
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      task_event_names[*(unsigned int *)(v1 + 36)],
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(unsigned __int16 *)(v1 + 72),
      *(unsigned __int16 *)(v1 + 74),
      *(unsigned __int16 *)(v1 + 76),
      *(unsigned __int16 *)(v1 + 78),
      *(unsigned __int16 *)(v1 + 80),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 84),
      *(unsigned __int16 *)(v1 + 92),
      *(unsigned __int8 *)(v1 + 94),
      *(_QWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 104));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
