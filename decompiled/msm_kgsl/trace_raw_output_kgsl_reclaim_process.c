__int64 __fastcall trace_raw_output_kgsl_reclaim_process(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 20) )
      v4 = "out";
    else
      v4 = "in";
    trace_event_printf(
      a1,
      "tgid=%u swapped=%u swapped_out_total=%u swap=%s\n",
      *(unsigned int *)(v1 + 8),
      *(unsigned int *)(v1 + 12),
      *(unsigned int *)(v1 + 16),
      v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
