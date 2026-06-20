__int64 __fastcall trace_raw_output_safg_sau_adjust_util(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d orig=%llu normal=%llu stall=%llu reduce_pct=%llu sau_result=%llu final_util=%llu report_policy=%d\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
