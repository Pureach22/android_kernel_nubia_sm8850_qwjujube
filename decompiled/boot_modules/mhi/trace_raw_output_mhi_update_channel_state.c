__int64 __fastcall trace_raw_output_mhi_update_channel_state(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  int v4; // w21
  __int64 v5; // x23
  const char *v6; // x20
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 12);
    v5 = *(unsigned __int16 *)(v1 + 8);
    v6 = *(const char **)(v1 + 24);
    v7 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 16),
                         &trace_raw_output_mhi_update_channel_state_symbols);
    trace_event_printf(a1, "%s: chan%d: %s state to: %s\n\n", (const char *)(v1 + v5), v4, v6, v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
