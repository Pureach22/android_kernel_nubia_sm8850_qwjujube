__int64 __fastcall trace_raw_output_walt_active_load_balance(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d misfit=%d prev_cpu=%d new_cpu=%d\n\n",
      *(_DWORD *)(v1 + 8),
      *(unsigned __int8 *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
