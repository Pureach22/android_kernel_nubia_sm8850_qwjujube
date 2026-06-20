__int64 __fastcall trace_raw_output_rdev_connect(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x9

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = "false";
    if ( *(_BYTE *)(v1 + 104) )
      v4 = "true";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), bssid: %pM, ssid: %s, auth type: %d, privacy: %s, wpa versions: %u, flags: 0x%x, previous bssid: %pM\n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      v1 + 60,
      v1 + 66,
      *(unsigned int *)(v1 + 100),
      v4,
      *(_DWORD *)(v1 + 108),
      *(_DWORD *)(v1 + 112),
      v1 + 116);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
