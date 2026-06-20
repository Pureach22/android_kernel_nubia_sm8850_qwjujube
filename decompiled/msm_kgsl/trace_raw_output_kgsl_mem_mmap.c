__int64 __fastcall trace_raw_output_kgsl_mem_mmap(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "useraddr=0x%lx gpuaddr=0x%llx size=%llu usage=%s id=%u flags=0x%llx\n",
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      (const char *)(v1 + 32),
      *(_DWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
