__int64 __fastcall trace_raw_output_cfg80211_links_removed(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "netdev:%s(%d), link_mask:%u\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(unsigned __int16 *)(v1 + 28));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
