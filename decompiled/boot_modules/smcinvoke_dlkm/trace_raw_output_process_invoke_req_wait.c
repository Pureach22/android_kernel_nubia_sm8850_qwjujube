__int64 __fastcall trace_raw_output_process_invoke_req_wait(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ob_name=%s ob_type=0x%02x op=0x%08x counts=%u\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
