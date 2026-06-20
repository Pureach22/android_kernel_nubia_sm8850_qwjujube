__int64 __fastcall trace_raw_output_sched_nbia_task_sched_switch(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "nbia_task_sched_switch pre %d (%s) affinity=%lx  next %d (%s) affinity=%lx \n\n",
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 56),
      (const char *)(v1 + 40),
      *(_QWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
