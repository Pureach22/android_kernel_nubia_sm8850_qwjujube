__int64 __fastcall trace_raw_output_adreno_gpu_vote_params(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cur_pwrlevel=%u prev_pwrlevel=%u avg_busy=%u penalty_up=%lu penalty_down=%lu first_step_down_count=%lu subsequent_"
      "step_down_count=%lu min_pwrlevel=%lu max_pwrlevel=%lu target_fps=%u num_samples_up=%lu num_samples_down=%lu mod_pe"
      "rcent=%u flags=0x%08x ticks=%llu\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      (unsigned __int16)*(_DWORD *)(v1 + 24),
      (unsigned __int64)*(unsigned int *)(v1 + 24) >> 16,
      (unsigned __int16)*(_DWORD *)(v1 + 28),
      (unsigned __int64)*(unsigned int *)(v1 + 28) >> 16,
      (unsigned __int16)*(_DWORD *)(v1 + 32),
      (unsigned __int64)*(unsigned int *)(v1 + 32) >> 16,
      *(_DWORD *)(v1 + 40),
      (unsigned __int16)*(_DWORD *)(v1 + 36),
      (unsigned __int64)*(unsigned int *)(v1 + 36) >> 16,
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 20),
      *(_QWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
