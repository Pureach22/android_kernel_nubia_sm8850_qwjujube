__int64 __fastcall trace_raw_output_kgsl_mem_sync_cache(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  int v4; // w8
  __int64 v5; // x7
  int v6; // w8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 40);
    if ( (v4 & 1) != 0 )
      v5 = 99;
    else
      v5 = 46;
    if ( (v4 & 2) != 0 )
      v6 = 105;
    else
      v6 = 46;
    trace_event_printf(
      a1,
      "gpuaddr=0x%llx size=%llu tgid=%u  usage=%s id=%u op=%c%c offset=%llu\n",
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 56),
      *(unsigned int *)(v1 + 32),
      v1 + 16,
      *(unsigned int *)(v1 + 36),
      v5,
      v6,
      *(_QWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
