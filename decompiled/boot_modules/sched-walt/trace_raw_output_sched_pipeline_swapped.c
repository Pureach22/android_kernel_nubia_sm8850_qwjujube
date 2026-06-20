__int64 __fastcall trace_raw_output_sched_pipeline_swapped(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "other_pid=%d other_comm=%s other_demand=%d other_coloc=%d other_new_pipeline_cpu=%d prime_pid=%d prime_comm=%s pri"
      "me_demand=%d prime_coloc=%d prime_new_pipeline_cpu=%d\n",
      *(_DWORD *)(v1 + 40),
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 44),
      (const char *)(v1 + 24),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 52));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
