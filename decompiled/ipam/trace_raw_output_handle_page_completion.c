__int64 __fastcall trace_raw_output_handle_page_completion(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x2
  const char *v5; // x7

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_DWORD *)(v1 + 40) == 35 )
      v4 = "WAN_CONS";
    else
      v4 = "WAN_COAL_CONS";
    if ( *(_BYTE *)(v1 + 26) )
      v5 = "true";
    else
      v5 = "false";
    trace_event_printf(
      a1,
      "%s: page=0x%pK pfn=0x%lx skb=0x%pK len=%u tmp=%s\n",
      v4,
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 16),
      *(unsigned __int16 *)(v1 + 24),
      v5);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
