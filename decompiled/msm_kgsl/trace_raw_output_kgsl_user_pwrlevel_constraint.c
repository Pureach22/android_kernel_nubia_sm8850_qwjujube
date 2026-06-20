__int64 __fastcall trace_raw_output_kgsl_user_pwrlevel_constraint(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  int v4; // w20
  __int64 v5; // x23
  const char *v6; // x21
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 12);
    v5 = *(unsigned __int16 *)(v1 + 8);
    v6 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(unsigned int *)(v1 + 16),
                         &trace_raw_output_kgsl_user_pwrlevel_constraint_symbols);
    v7 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(unsigned int *)(v1 + 20),
                         &trace_raw_output_kgsl_user_pwrlevel_constraint_symbols_157);
    trace_event_printf(
      a1,
      "d_name=%s ctx=%u constraint_type=%s constraint_subtype=%s\n",
      (const char *)(v1 + v5),
      v4,
      v6,
      v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
