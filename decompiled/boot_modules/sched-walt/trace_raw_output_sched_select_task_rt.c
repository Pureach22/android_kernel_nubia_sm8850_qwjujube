__int64 __fastcall trace_raw_output_sched_select_task_rt(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s fastpath=%u best_cpu=%d reduce_mask=0x%lx lowest_mask=0x%lx\n",
      *(_DWORD *)(v1 + 8),
      (const char *)(v1 + 12),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
