__int64 __fastcall trace_raw_output_cfg80211_probe_status(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x6

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 48) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "netdev:%s(%d) addr:%pM, cookie: %llu, acked: %s\n",
      v1 + 8,
      *(unsigned int *)(v1 + 24),
      v1 + 28,
      *(_QWORD *)(v1 + 40),
      v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
