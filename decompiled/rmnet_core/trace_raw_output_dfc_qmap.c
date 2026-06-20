__int64 __fastcall trace_raw_output_dfc_qmap(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  unsigned __int64 v4; // x21
  int v5; // w20
  const char *v6; // x22
  __int64 v7; // x2
  const char *v8; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_QWORD *)(v1 + 16);
    v5 = *(unsigned __int8 *)(v1 + 28);
    if ( *(_BYTE *)(v1 + 8) )
      v6 = "<--";
    else
      v6 = "-->";
    if ( v4 >= 0x50 )
      v7 = 80;
    else
      v7 = *(_QWORD *)(v1 + 16);
    v8 = (const char *)trace_print_array_seq(a1 + 136, v1 + *(unsigned __int16 *)(v1 + 24), v7, 1);
    trace_event_printf(a1, "[0x%02x]:[%zu] %s %s\n", v5, v4, v6, v8);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
