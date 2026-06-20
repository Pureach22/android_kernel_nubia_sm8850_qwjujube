__int64 __fastcall trace_raw_output_rpmh_send_msg(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  int v4; // w20
  __int64 v5; // x22
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 12);
    v5 = *(unsigned __int16 *)(v1 + 8);
    v6 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(unsigned int *)(v1 + 16),
                         &trace_raw_output_rpmh_send_msg_symbols);
    trace_event_printf(
      a1,
      "%s: tcs(m): %d [%s] cmd(n): %d msgid: %#x addr: %#x data: %#x complete: %d\n",
      (const char *)(v1 + v5),
      v4,
      v6,
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(unsigned __int8 *)(v1 + 36));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
