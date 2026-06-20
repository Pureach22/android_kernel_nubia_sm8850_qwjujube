__int64 __fastcall trace_raw_output_walt_newidle_balance(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d busy_cpu=%d pulled=%d nr_running=%u rt_nr_running=%u nr_iowait=%d help_min_cap=%d avg_idle=%llu enough_idle"
      "=%d overloaded=%d pid=%d\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(unsigned __int8 *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(unsigned __int8 *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
