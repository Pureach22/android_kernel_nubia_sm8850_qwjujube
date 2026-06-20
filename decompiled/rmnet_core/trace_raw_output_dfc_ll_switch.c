__int64 __fastcall trace_raw_output_dfc_ll_switch(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  int v4; // w21
  __int64 v5; // x23
  int v6; // w20
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int8 *)(v1 + 13);
    v5 = *(unsigned __int16 *)(v1 + 8);
    v6 = *(unsigned __int8 *)(v1 + 12);
    v7 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 16),
                         *(unsigned __int8 *)(v1 + 13),
                         1);
    trace_event_printf(a1, "%s type=%u num_bearer=%u bearers={%s}\n", (const char *)(v1 + v5), v6, v4, v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
