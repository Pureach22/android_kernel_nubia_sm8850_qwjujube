__int64 __fastcall trace_raw_output_sched_task_handler(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "comm=%s pid=%d param=%d val=%d callers=%ps <- %ps <- %ps <- %ps <- %ps <- %ps\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(const void **)(v1 + 40),
      *(const void **)(v1 + 48),
      *(const void **)(v1 + 56),
      *(const void **)(v1 + 64),
      *(const void **)(v1 + 72),
      *(const void **)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
