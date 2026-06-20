__int64 __fastcall trace_raw_output_hyp_assign_info(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  const char *v4; // x20
  const char *v5; // x21
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 16),
                         *(unsigned int *)(v1 + 8),
                         4);
    v5 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 20),
                         *(unsigned int *)(v1 + 12),
                         4);
    v6 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 24),
                         *(unsigned int *)(v1 + 12),
                         4);
    trace_event_printf(a1, "srcVMIDs: %s dstVMIDs: %s dstPerms: %s\n", v4, v5, v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
