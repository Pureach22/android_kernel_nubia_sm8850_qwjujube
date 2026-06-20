__int64 __fastcall trace_raw_output_print_udp(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "UDP: skbaddr=%pK, len=%d source=%s %u dest=%s %u ip_id=%u\n",
      *(const void **)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 20)),
      bswap32(*(unsigned __int16 *)(v1 + 28)) >> 16,
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 24)),
      bswap32(*(unsigned __int16 *)(v1 + 30)) >> 16,
      *(unsigned __int16 *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
