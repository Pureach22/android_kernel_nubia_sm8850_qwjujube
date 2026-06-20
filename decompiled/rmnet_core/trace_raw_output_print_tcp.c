__int64 __fastcall trace_raw_output_print_tcp(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "TCP: skbaddr=%pK, len=%d source=%s %u dest=%s %u seq=%u ack_seq=%u syn=%u ack=%u fin=%u\n",
      *(_QWORD *)(v1 + 8),
      *(unsigned int *)(v1 + 16),
      v1 + *(unsigned __int16 *)(v1 + 20),
      bswap32(*(unsigned __int16 *)(v1 + 28)) >> 16,
      v1 + *(unsigned __int16 *)(v1 + 24),
      bswap32(*(unsigned __int16 *)(v1 + 30)) >> 16,
      bswap32(*(_DWORD *)(v1 + 32)),
      bswap32(*(_DWORD *)(v1 + 36)),
      *(_BYTE *)(v1 + 40) != 0,
      *(unsigned __int8 *)(v1 + 41) != 0,
      *(_BYTE *)(v1 + 42) != 0);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
