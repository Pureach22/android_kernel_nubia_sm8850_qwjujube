__int64 __fastcall trace_raw_output_dfc_adjust_grant(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "mid=%u bid=%u grant=%u rx=%u inflight=%u adjusted_grant=%u\n",
      *(unsigned __int8 *)(v1 + 8),
      *(unsigned __int8 *)(v1 + 9),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
