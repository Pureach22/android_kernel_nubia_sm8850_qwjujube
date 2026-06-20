__int64 __fastcall trace_raw_output_rdev_tdls_mgmt(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x10

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = "true";
    if ( !*(_BYTE *)(v1 + 80) )
      v4 = "false";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), %pM, link_id: %d, action_code: %u dialog_token: %u, status_code: %u, peer_capability: %u initia"
      "tor: %s buf: %#.2x \n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      v1 + 60,
      *(unsigned int *)(v1 + 68),
      *(unsigned __int8 *)(v1 + 72),
      *(unsigned __int8 *)(v1 + 73),
      *(unsigned __int16 *)(v1 + 74),
      *(_DWORD *)(v1 + 76),
      v4,
      *(unsigned __int8 *)(v1 + *(unsigned __int16 *)(v1 + 84)));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
