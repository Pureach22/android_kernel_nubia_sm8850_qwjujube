__int64 __fastcall trace_raw_output_sched_set_preferred_cluster(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "group_id %d total_demand %llu skip_min %d prev_skip_min %d start_ktime_ts %llu last_update %llu min_coloc_ns %u do"
      "wnmigrate_ts %llu group_upmigrate %u group_downmigrate %u\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(unsigned __int8 *)(v1 + 24),
      *(unsigned __int8 *)(v1 + 25),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
