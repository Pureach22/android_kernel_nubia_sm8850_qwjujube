__int64 __fastcall trace_raw_output_ipa3_replenish_rx_page_recycle(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 24) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "wan_cons type=%u: page=0x%pK pfn=0x%lx tmp=%s\n",
      *(_DWORD *)(v1 + 8),
      *(const void **)(v1 + 16),
      *(_QWORD *)(v1 + 32),
      v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
