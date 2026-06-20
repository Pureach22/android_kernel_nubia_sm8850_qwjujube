__int64 __fastcall trace_raw_output_kgsl_issueibcmds(__int64 a1)
{
  __int64 v1; // x25
  __int64 result; // x0
  __int64 v4; // x2
  int v5; // w20
  int v6; // w21
  int v7; // w22
  __int64 v8; // x27
  const char *v9; // x23
  int v10; // w24
  const char *v11; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_DWORD *)(v1 + 20);
    v4 = *(unsigned int *)(v1 + 24);
    v6 = *(_DWORD *)(v1 + 12);
    v7 = *(_DWORD *)(v1 + 16);
    v8 = *(unsigned __int16 *)(v1 + 8);
    if ( (_DWORD)v4 )
      v9 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_kgsl_issueibcmds___flags);
    else
      v9 = "None";
    v10 = *(_DWORD *)(v1 + 28);
    v11 = kgsl_context_type(*(_DWORD *)(v1 + 32));
    trace_event_printf(
      a1,
      "d_name=%s ctx=%u ib=0x0 numibs=%u ts=%u flags=%s result=%d type=%s\n",
      (const char *)(v1 + v8),
      v6,
      v7,
      v5,
      v9,
      v10,
      v11);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
