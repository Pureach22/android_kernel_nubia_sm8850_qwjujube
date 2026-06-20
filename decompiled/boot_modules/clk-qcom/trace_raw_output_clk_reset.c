__int64 __fastcall trace_raw_output_clk_reset(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 24) )
      v4 = "assert";
    else
      v4 = "deassert";
    trace_event_printf(
      a1,
      "%s %s offset=0x%x id=%lu\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      v4,
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
