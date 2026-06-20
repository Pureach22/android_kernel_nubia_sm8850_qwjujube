__int64 __fastcall trace_raw_output_rdev_assoc(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x7

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 72) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), bssid: %pM, previous bssid: %pM, use mfp: %s, flags: 0x%x\n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      v1 + 60,
      v1 + 66,
      v4,
      *(_DWORD *)(v1 + 76));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
