__int64 __fastcall trace_raw_output_cfg80211_get_bss(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, band: %d, freq: %u.%03u, %pM, buf: %#.2x, bss_type: %d, privacy: %d\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(unsigned __int16 *)(v1 + 48),
      (const void *)(v1 + 50),
      *(unsigned __int8 *)(v1 + *(unsigned __int16 *)(v1 + 56)),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
