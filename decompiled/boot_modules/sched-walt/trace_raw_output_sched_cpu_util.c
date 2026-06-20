__int64 __fastcall trace_raw_output_sched_cpu_util(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d nr_running=%d cpu_util=%ld cpu_util_cum=%ld capacity_curr=%lu capacity=%lu capacity_orig=%lu sibling_cluste"
      "r=%d idle_exit_latency=%u irqload=%llu online=%u, inactive=%u, halted=%u, reserved=%u, high_irq_load=%u enforce_hi"
      "gh_irq_load=%d nr_rtg_hp=%u prs_gprs=%llu lowest_mask=0x%x thermal_pressure=%lu\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 128),
      *(_DWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 88),
      *(unsigned __int8 *)(v1 + 92),
      *(_DWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 104),
      *(_DWORD *)(v1 + 112),
      *(_QWORD *)(v1 + 120));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
