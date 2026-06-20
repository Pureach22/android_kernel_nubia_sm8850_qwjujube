__int64 __fastcall trace_raw_output_api_disconnect(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x4

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 24) )
      v4 = "/p2p";
    else
      v4 = (const char *)&unk_B8EF0;
    trace_event_printf(
      a1,
      " vif:%s(%d%s) reconnect:%d\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 28)),
      *(_DWORD *)(v1 + 8),
      v4,
      *(_DWORD *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
