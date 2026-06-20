__int64 __fastcall trace_raw_output_cfg80211_inform_bss_frame(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, band: %d, freq: %u.%03usignal: %d, tsb:%llu, detect_tsf:%llu, tsf_bssid: %pM\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(unsigned __int16 *)(v1 + 48),
      *(_DWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      (const void *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
