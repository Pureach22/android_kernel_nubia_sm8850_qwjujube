__int64 __fastcall trace_raw_output_lookup_sgl(__int64 a1)
{
  __int64 v1; // x22
  __int64 result; // x0
  int v4; // w20
  const char *v5; // x21
  const char *v6; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 12),
                         *(unsigned __int16 *)(v1 + 8),
                         8);
    v6 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 16),
                         *(unsigned __int16 *)(v1 + 8),
                         8);
    trace_event_printf(
      a1,
      "SGL entries: %d SGL IPA bases: %s SGL sizes: %s ret: %d memparcel_hdl: 0x%x\n",
      v4,
      v5,
      v6,
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
