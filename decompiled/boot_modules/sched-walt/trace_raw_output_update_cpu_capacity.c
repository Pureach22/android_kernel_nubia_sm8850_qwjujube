__int64 __fastcall trace_raw_output_update_cpu_capacity(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d arch_capacity=%lu thermal_cap=%lu fmax_capacity=%lu max_freq=%lu max_possible_freq=%lu rq_cpu_capacity_orig=%lu\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
