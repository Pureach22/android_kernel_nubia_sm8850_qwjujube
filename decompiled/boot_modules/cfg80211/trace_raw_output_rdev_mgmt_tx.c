__int64 __fastcall trace_raw_output_rdev_mgmt_tx(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x7
  const char *v5; // x12
  const char *v6; // x8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 54) )
      v4 = "true";
    else
      v4 = "false";
    if ( *(_BYTE *)(v1 + 60) )
      v5 = "true";
    else
      v5 = "false";
    if ( *(_BYTE *)(v1 + 61) )
      v6 = "true";
    else
      v6 = "false";
    trace_event_printf(
      a1,
      "%s, wdev(%u), band: %d, freq: %u.%03u, offchan: %s, wait: %u, no cck: %s, dont wait for ack: %s\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(unsigned __int16 *)(v1 + 52),
      v4,
      *(_DWORD *)(v1 + 56),
      v5,
      v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
