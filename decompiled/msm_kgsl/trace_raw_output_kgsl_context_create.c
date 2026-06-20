__int64 __fastcall trace_raw_output_kgsl_context_create(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  __int64 v4; // x2
  int v5; // w20
  __int64 v6; // x25
  const char *v7; // x21
  int v8; // w22
  const char *v9; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_DWORD *)(v1 + 12);
    v4 = *(unsigned int *)(v1 + 16);
    v6 = *(unsigned __int16 *)(v1 + 8);
    if ( (_DWORD)v4 )
      v7 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_kgsl_context_create___flags);
    else
      v7 = "None";
    v8 = *(_DWORD *)(v1 + 20);
    v9 = kgsl_context_type(*(_DWORD *)(v1 + 24));
    trace_event_printf(a1, "d_name=%s ctx=%u flags=%s priority=%u type=%s\n", (const char *)(v1 + v6), v5, v7, v8, v9);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
