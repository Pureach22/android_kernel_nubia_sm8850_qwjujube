__int64 __fastcall trace_raw_output_kgsl_constraint(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  const char *v6; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = trace_print_symbols_seq(a1 + 136, *(unsigned int *)(v1 + 12), &trace_raw_output_kgsl_constraint_symbols);
    if ( *(_DWORD *)(v1 + 20) )
      v6 = "ON";
    else
      v6 = "OFF";
    trace_event_printf(
      a1,
      "d_name=%s constraint_type=%s constraint_value=%u status=%s ticks=%llu\n",
      v1 + v4,
      v5,
      *(unsigned int *)(v1 + 16),
      v6,
      *(_QWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
