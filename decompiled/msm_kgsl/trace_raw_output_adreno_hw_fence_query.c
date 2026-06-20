__int64 __fastcall trace_raw_output_adreno_hw_fence_query(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x2
  const char *v7; // x4

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_QWORD *)(v1 + 8);
    v5 = *(_QWORD *)(v1 + 16);
    v6 = *(unsigned int *)(v1 + 24);
    if ( (_DWORD)v6 )
      v7 = (const char *)trace_print_flags_seq(a1 + 136, "|", v6, &trace_raw_output_adreno_hw_fence_query___flags);
    else
      v7 = "none";
    trace_event_printf(
      a1,
      "id=%lld seqno=%lld sw_status=%s name=%s val=%s\n",
      v4,
      v5,
      v7,
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 28)),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 32)));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
