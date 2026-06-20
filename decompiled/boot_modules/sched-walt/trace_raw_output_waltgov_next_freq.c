__int64 __fastcall trace_raw_output_waltgov_next_freq(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%u util=%lu max=%lu raw_freq=%u freq=%u policy_min_freq=%u policy_max_freq=%u cached_raw_freq=%u need_update=%"
      "d thermal_isolated=%d rt_util=%u driv_cpu=%u reason=0x%x smart_freq=%u ipc_smart_freq=%u final_freq=%u\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(unsigned __int8 *)(v1 + 52),
      *(unsigned __int8 *)(v1 + 53),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
