__int64 __fastcall trace_raw_output_freq_qos_request(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "variation=%s client=%pS type=%d val=%d\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(const void **)(v1 + 32),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
