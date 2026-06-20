__int64 __fastcall trace_raw_output_sde_perf_crtc_update(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "crtc=%d mnoc=[%llu %llu] llcc=[%llu %llu] ebi=[%llu %llu] clk=%u stop=%d ubus=%d uclk=%d %d\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 64),
      *(unsigned __int8 *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
