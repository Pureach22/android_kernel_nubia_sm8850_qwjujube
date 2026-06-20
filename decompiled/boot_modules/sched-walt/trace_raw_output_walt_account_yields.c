__int64 __fastcall trace_raw_output_walt_account_yields(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "wallclock=%llu start_ts=%llu continuous_windows=%u global_yield_cnt=%u target_yield_th=%u global_sleep_cnt=%u targ"
      "et_induced_sleep_th=%u\n",
      *(_QWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(unsigned __int8 *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36),
      *(_DWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
