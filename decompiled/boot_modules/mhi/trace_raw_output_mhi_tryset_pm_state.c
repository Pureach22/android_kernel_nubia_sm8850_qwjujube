__int64 __fastcall trace_raw_output_mhi_tryset_pm_state(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x21
  const char *v5; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 12),
                         &trace_raw_output_mhi_tryset_pm_state_symbols);
    trace_event_printf(a1, "%s: PM state: %s\n\n", (const char *)(v1 + v4), v5);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
