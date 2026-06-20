__int64 __fastcall trace_raw_output_print_pfn(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  unsigned int v4; // w21
  const void *v5; // x20
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 16);
    v5 = *(const void **)(v1 + 8);
    v6 = (const char *)trace_print_array_seq(a1 + 136, v1 + *(unsigned __int16 *)(v1 + 20), v4, 8);
    trace_event_printf(a1, "skbaddr=%pK count=%d pfn=%s\n", v5, v4, v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
