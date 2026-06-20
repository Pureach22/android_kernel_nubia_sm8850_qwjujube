__int64 __fastcall trace_raw_output_msm_vidc_perf(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s: power: inst: clk %lld %lld %lld %lld %lld ddr %d llcc %d dcvs flags %#x, core: clk_idx %d ddr %lld llcc %lld\n"
      "\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
