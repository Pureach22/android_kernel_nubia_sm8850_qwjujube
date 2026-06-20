__int64 __fastcall trace_raw_output_rdev_tx_control_port(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x6
  const char *v5; // x7

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = bswap32(*(unsigned __int16 *)(v1 + 66)) >> 16;
    if ( *(_BYTE *)(v1 + 68) )
      v5 = "true";
    else
      v5 = "false";
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), %pM, proto: 0x%x, unencrypted: %s, link: %d\n",
      v1 + 8,
      v1 + 40,
      *(unsigned int *)(v1 + 56),
      v1 + 60,
      v4,
      v5,
      *(_DWORD *)(v1 + 72));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
