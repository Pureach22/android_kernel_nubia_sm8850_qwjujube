__int64 __fastcall trace_raw_output_rdev_add_key(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 73) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), link_id: %d, key_index: %u, mode: %u, pairwise: %s, mac addr: %pM\n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      *(unsigned int *)(v1 + 68),
      *(unsigned __int8 *)(v1 + 72),
      *(unsigned __int8 *)(v1 + 74),
      v4,
      v1 + 60);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
