__int64 __fastcall trace_raw_output_kgsl_reclaim_memdesc(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = "out";
    if ( !*(_BYTE *)(v1 + 48) )
      v4 = "in";
    trace_event_printf(
      a1,
      "gpuaddr=0x%llx size=%llu page_count=%u tgid=%u id=%u flags=0x%llx swap=%s\n",
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(unsigned int *)(v1 + 24),
      *(unsigned int *)(v1 + 28),
      *(unsigned int *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
