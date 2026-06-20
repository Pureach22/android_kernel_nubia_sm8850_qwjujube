__int64 __fastcall trace_raw_output_dfc_watchdog(__int64 a1)
{
  unsigned __int8 *v1; // x20
  __int64 result; // x0

  v1 = *(unsigned __int8 **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "mid=%u bid=%u event=%u\n", v1[8], v1[9], v1[10]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
