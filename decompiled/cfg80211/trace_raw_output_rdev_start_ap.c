__int64 __fastcall trace_raw_output_rdev_start_ap(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x9

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = "false";
    if ( *(_BYTE *)(v1 + 144) )
      v4 = "true";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), AP settings - ssid: %s, band: %d, control freq: %u.%03u, width: %d, cf1: %u.%03u, cf2: %u, punc"
      "t: 0x%x, beacon interval: %d, dtim period: %d, hidden ssid: %d, wpa versions: %u, privacy: %s, auth type: %d, inac"
      "tivity timeout: %d, link_id: %d\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      *(_DWORD *)(v1 + 56),
      (const char *)(v1 + 100),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(unsigned __int16 *)(v1 + 88),
      *(_DWORD *)(v1 + 92),
      *(_DWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 136),
      *(_DWORD *)(v1 + 140),
      v4,
      *(_DWORD *)(v1 + 148),
      *(_DWORD *)(v1 + 152),
      *(_DWORD *)(v1 + 156));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
