__int64 __fastcall trace_raw_output_hyp_assign_batch_start(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  unsigned int v4; // w20
  __int64 v5; // x21
  const char *v6; // x22
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 8);
    v5 = *(_QWORD *)(v1 + 16);
    v6 = (const char *)trace_print_array_seq(a1 + 136, v1 + *(unsigned __int16 *)(v1 + 24), v4, 8);
    v7 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 28),
                         *(unsigned int *)(v1 + 8),
                         8);
    trace_event_printf(a1, "num entries: %d batch size: %llu phys addrs: %s sizes: %s\n", v4, v5, v6, v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
