__int64 __fastcall trace_raw_output_sched_votable_result(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "votable_name=%s eff_client=%d eff_result=%d (client's vote: %d:%d,  %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d)\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 36),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 92));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
