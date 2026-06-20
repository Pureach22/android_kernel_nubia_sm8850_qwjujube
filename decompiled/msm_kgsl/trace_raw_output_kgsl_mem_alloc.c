__int64 __fastcall trace_raw_output_kgsl_mem_alloc(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "gpuaddr=0x%llx size=%llu tgid=%u usage=%s id=%u flags=0x%llx\n",
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 28),
      *(_DWORD *)(v1 + 44),
      *(_QWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
