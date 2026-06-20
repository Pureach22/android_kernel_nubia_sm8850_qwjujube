__int64 __fastcall trace_raw_output_rdev_set_multicast_to_unicast(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 60) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(a1, "%s, netdev:%s(%d), unicast: %s\n", v1 + 8, v1 + 40, *(unsigned int *)(v1 + 56), v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
