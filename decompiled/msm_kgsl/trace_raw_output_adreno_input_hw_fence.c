__int64 __fastcall trace_raw_output_adreno_input_hw_fence(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  __int64 v4; // x2
  __int64 v5; // x22
  int v6; // w20
  __int64 v7; // x21
  const char *v8; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_QWORD *)(v1 + 24);
    v4 = *(_QWORD *)(v1 + 32);
    v6 = *(_DWORD *)(v1 + 8);
    v7 = *(_QWORD *)(v1 + 16);
    if ( v4 )
      v8 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_adreno_input_hw_fence___flags);
    else
      v8 = "none";
    trace_event_printf(
      a1,
      "ctx=%u id=%lld seqno=%lld flags=%s name=%s\n",
      v6,
      v7,
      v5,
      v8,
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 40)));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
