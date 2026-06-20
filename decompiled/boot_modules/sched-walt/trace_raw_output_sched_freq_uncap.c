__int64 __fastcall trace_raw_output_sched_freq_uncap(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cluster=%d nr_big=%d wakeup_ctr_sum=%d current_reasons=0x%x cluster_active_reason=0x%x max_cap=%lu max_reason=0x%x\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
