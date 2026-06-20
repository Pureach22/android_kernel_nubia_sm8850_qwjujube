__int64 __fastcall trace_raw_output_sched_get_nr_running_avg(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d nr=%d nr_misfit=%d nr_max=%d nr_scaled=%d nr_giant=%d trailblazer_boost_cpu=%d\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(unsigned __int8 *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
