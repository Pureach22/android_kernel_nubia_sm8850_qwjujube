__int64 __fastcall trace_raw_output_sched_find_best_target(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s start_cpu=%d candidates=%#lx most_spare_cap=%d order_index=%d end_index=%d skip=%d running=%d min_u"
      "til=%lu spare_rq_cpu=%d min_runnable=%u\n",
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(unsigned __int8 *)(v1 + 72),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
