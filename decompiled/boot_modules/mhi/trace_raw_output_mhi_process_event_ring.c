__int64 __fastcall trace_raw_output_mhi_process_event_ring(__int64 a1)
{
  __int64 v1; // x24
  __int64 result; // x0
  const void *v4; // x20
  __int64 v5; // x21
  __int64 v6; // x25
  int v7; // w22
  int v8; // w23
  const char *v9; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_QWORD *)(v1 + 24);
    v4 = *(const void **)(v1 + 32);
    v6 = *(unsigned __int16 *)(v1 + 8);
    v7 = *(_DWORD *)(v1 + 12);
    v8 = *(_DWORD *)(v1 + 16);
    v9 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 20),
                         &trace_raw_output_mhi_process_event_ring_symbols);
    trace_event_printf(
      a1,
      "%s: TRE: 0x%p TRE buf: 0x%llx DWORD0: 0x%08x DWORD1: 0x%08x State: %s\n\n",
      (const char *)(v1 + v6),
      v4,
      v5,
      v7,
      v8,
      v9);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
