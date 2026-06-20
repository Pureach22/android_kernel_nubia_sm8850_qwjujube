__int64 __fastcall trace_raw_output_cfg80211_rx_control_port(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x7

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 40) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "netdev:%s(%d), len=%d, %pM, proto: 0x%x, unencrypted: %s, link: %d\n",
      v1 + 8,
      *(unsigned int *)(v1 + 24),
      *(unsigned int *)(v1 + 28),
      v1 + 32,
      *(unsigned __int16 *)(v1 + 38),
      v4,
      *(_DWORD *)(v1 + 44));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
