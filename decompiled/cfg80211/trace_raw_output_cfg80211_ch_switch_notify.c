__int64 __fastcall trace_raw_output_cfg80211_ch_switch_notify(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "netdev:%s(%d), band: %d, control freq: %u.%03u, width: %d, cf1: %u.%03u, cf2: %u, punct: 0x%x, link:%d\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(unsigned __int16 *)(v1 + 56),
      *(_DWORD *)(v1 + 60));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
