__int64 __fastcall trace_raw_output_sched_compute_energy(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s util=%lu prev_cpu=%d prev_energy=%lu eval_cpu=%d eval_energy=%lu best_energy_cpu=%d best_energy=%lu"
      ", fcpu s m c = %u %lu %lu %lu, %u %lu %lu %lu, %u %lu %lu %lu\n",
      *(_DWORD *)(v1 + 8),
      (const char *)(v1 + 12),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 104),
      *(_QWORD *)(v1 + 128),
      *(_QWORD *)(v1 + 152),
      *(_DWORD *)(v1 + 92),
      *(_QWORD *)(v1 + 112),
      *(_QWORD *)(v1 + 136),
      *(_QWORD *)(v1 + 160),
      *(_DWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 120),
      *(_QWORD *)(v1 + 144),
      *(_QWORD *)(v1 + 168));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
