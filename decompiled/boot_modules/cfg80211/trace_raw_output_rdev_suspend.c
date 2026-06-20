__int64 __fastcall trace_raw_output_rdev_suspend(__int64 a1)
{
  unsigned __int8 *v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(unsigned __int8 **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( v1[47] )
      v4 = (const char *)&unk_B6F9E;
    else
      v4 = "(Not configured!)";
    trace_event_printf(
      a1,
      "%s, wow%s - any: %d, disconnect: %d, magic pkt: %d, gtk rekey failure: %d, eap identify req: %d, four way handshak"
      "e: %d, rfkill release: %d.\n",
      v1 + 8,
      v4,
      v1[40],
      v1[41],
      v1[42],
      v1[43],
      v1[44],
      v1[45],
      v1[46]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
