__int64 __fastcall trace_raw_output_map_mem_s2(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  int v4; // w21
  int v5; // w20
  const char *v6; // x22
  const char *v7; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 12);
    v5 = *(_DWORD *)(v1 + 8);
    v6 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 16),
                         *(unsigned __int16 *)(v1 + 12),
                         8);
    v7 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 20),
                         *(unsigned __int16 *)(v1 + 12),
                         8);
    trace_event_printf(
      a1,
      "MEM_ACCEPT successful memparcel hdl: 0x%x SGL entries: %d SGL IPA bases: %s SGL sizes: %s\n",
      v5,
      v4,
      v6,
      v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
