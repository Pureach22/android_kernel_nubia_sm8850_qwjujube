__int64 __fastcall trace_raw_output_cfg80211_pmksa_candidate_notify(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x6

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 38) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "netdev:%s(%d), index:%d, bssid: %pM, pre auth: %s\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      (const void *)(v1 + 32),
      v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
