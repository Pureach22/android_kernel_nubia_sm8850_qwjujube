__int64 __fastcall trace_raw_output_cfg80211_scan_done(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x2

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 51) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(a1, "aborted: %s, scan start (TSF): %llu, tsf_bssid: %pM\n", v4, *(_QWORD *)(v1 + 56), v1 + 64);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
