__int64 __fastcall trace_raw_output_adreno_preempt_trigger(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "trigger from id=%d to id=%d cntl=%x ticks=%llu\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
