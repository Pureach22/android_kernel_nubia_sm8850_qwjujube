__int64 __fastcall trace_raw_output_cfg80211_reg_can_beacon(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, band: %d, control freq: %u.%03u, width: %d, cf1: %u.%03u, cf2: %u, punct: 0x%x, iftype=%d prohibited_flags=0x%"
      "x permitting_flags=0x%x\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(unsigned __int16 *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
