__int64 __fastcall trace_raw_output_kgsl_mem_free(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_QWORD *)(v1 + 8);
    v5 = *(_QWORD *)(v1 + 16);
    v6 = (const char *)trace_print_symbols_seq(a1 + 136, *(int *)(v1 + 24), &trace_raw_output_kgsl_mem_free_symbols);
    trace_event_printf(
      a1,
      "gpuaddr=0x%llx size=%llu type=%s tgid=%u usage=%s id=%u\n",
      v4,
      v5,
      v6,
      *(_DWORD *)(v1 + 32),
      (const char *)(v1 + 36),
      *(_DWORD *)(v1 + 52));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
