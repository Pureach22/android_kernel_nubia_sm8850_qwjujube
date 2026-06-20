__int64 __fastcall trace_raw_output_kgsl_mem_timestamp_template(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x23
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_QWORD *)(v1 + 16);
    v5 = *(_QWORD *)(v1 + 24);
    v6 = *(unsigned __int16 *)(v1 + 8);
    v7 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 32),
                         &trace_raw_output_kgsl_mem_timestamp_template_symbols);
    trace_event_printf(
      a1,
      "d_name=%s gpuaddr=0x%llx size=%llu type=%s usage=%s id=%u ctx=%u curr_ts=%u free_ts=%u\n",
      (const char *)(v1 + v6),
      v4,
      v5,
      v7,
      (const char *)(v1 + 36),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
