__int64 __fastcall trace_raw_output_sched_client_vote(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "votable_name=%s client=%d enable=%d val=%d\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(unsigned __int8 *)(v1 + 28),
      *(_DWORD *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
