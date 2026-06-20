__int64 __fastcall trace_raw_output_mhi_intvec_states(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  __int64 v4; // x24
  const char *v5; // x20
  const char *v6; // x21
  const char *v7; // x22
  const char *v8; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = (const char *)trace_print_symbols_seq(a1 + 136, *(int *)(v1 + 12), &trace_raw_output_mhi_intvec_states_symbols);
    v6 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 16),
                         &trace_raw_output_mhi_intvec_states_symbols_118);
    v7 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 20),
                         &trace_raw_output_mhi_intvec_states_symbols_125);
    v8 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 24),
                         &trace_raw_output_mhi_intvec_states_symbols_126);
    trace_event_printf(
      a1,
      "%s: Local EE: %s State: %s Device EE: %s Dev State: %s\n\n",
      (const char *)(v1 + v4),
      v5,
      v6,
      v7,
      v8);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
