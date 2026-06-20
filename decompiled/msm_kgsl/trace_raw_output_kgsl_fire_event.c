__int64 __fastcall trace_raw_output_kgsl_fire_event(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  int v4; // w20
  int v5; // w21
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 8);
    v5 = *(_DWORD *)(v1 + 12);
    v6 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(unsigned int *)(v1 + 16),
                         &trace_raw_output_kgsl_fire_event_symbols);
    trace_event_printf(
      a1,
      "ctx=%u ts=%u type=%s age=%u cb=%pS\n",
      v4,
      v5,
      v6,
      *(_DWORD *)(v1 + 20),
      *(const void **)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
