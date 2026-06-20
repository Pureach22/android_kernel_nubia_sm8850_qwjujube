__int64 __fastcall trace_raw_output_print_skb_gso(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5
  unsigned int v5; // w8
  unsigned int v6; // w10
  const char *v7; // x6

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_WORD *)(v1 + 28) == 8 )
      v4 = "IPv4";
    else
      v4 = "IPv6";
    v5 = bswap32(*(unsigned __int16 *)(v1 + 24)) >> 16;
    v6 = bswap32(*(unsigned __int16 *)(v1 + 26)) >> 16;
    if ( *(_WORD *)(v1 + 30) == 6 )
      v7 = "TCP";
    else
      v7 = "UDP";
    trace_event_printf(
      a1,
      "GSO: skbaddr=%pK, len=%d, data_len=%d, [%s][%s] src=%s %u dest=%s %u\n",
      *(const void **)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      v4,
      v7,
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 32)),
      v5,
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 36)),
      v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
