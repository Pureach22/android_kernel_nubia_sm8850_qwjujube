__int64 __fastcall trace_raw_output_print_icmp(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x6
  const char *v5; // x4

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = bswap32(*(unsigned __int16 *)(v1 + 24)) >> 16;
    if ( *(_WORD *)(v1 + 20) == 8 )
      v5 = "IPv4";
    else
      v5 = "IPv6";
    trace_event_printf(
      a1,
      "ICMP: skbaddr=%pK, len=%d, [%s] type=%u sequence=%u source=%s dest=%s\n",
      *(_QWORD *)(v1 + 8),
      *(unsigned int *)(v1 + 16),
      v5,
      *(unsigned __int8 *)(v1 + 22),
      v4,
      v1 + *(unsigned __int16 *)(v1 + 28),
      v1 + *(unsigned __int16 *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
