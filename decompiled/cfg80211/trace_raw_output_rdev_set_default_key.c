__int64 __fastcall trace_raw_output_rdev_set_default_key(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x7
  const char *v5; // x8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 65) )
      v4 = "true";
    else
      v4 = "false";
    if ( *(_BYTE *)(v1 + 66) )
      v5 = "true";
    else
      v5 = "false";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), link_id: %d, key index: %u, unicast: %s, multicast: %s\n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      *(unsigned int *)(v1 + 60),
      *(unsigned __int8 *)(v1 + 64),
      v4,
      v5);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
