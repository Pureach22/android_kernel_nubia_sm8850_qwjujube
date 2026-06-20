__int64 __fastcall trace_raw_output_kgsl_gen7_irq_status(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x2
  __int64 v5; // x22
  const char *v6; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned int *)(v1 + 12);
    v5 = *(unsigned __int16 *)(v1 + 8);
    if ( (_DWORD)v4 )
      v6 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_kgsl_gen7_irq_status___flags);
    else
      v6 = "None";
    trace_event_printf(a1, "d_name=%s status=%s\n", (const char *)(v1 + v5), v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
