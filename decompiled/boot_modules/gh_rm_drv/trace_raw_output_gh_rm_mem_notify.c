__int64 __fastcall trace_raw_output_gh_rm_mem_notify(__int64 a1)
{
  __int64 v1; // x24
  __int64 result; // x0
  int v4; // w20
  int v5; // w21
  int v6; // w22
  int v7; // w23
  const char *v8; // x6

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 20);
    v5 = *(_DWORD *)(v1 + 8);
    v6 = *(unsigned __int8 *)(v1 + 12);
    v7 = *(_DWORD *)(v1 + 16);
    if ( *(_WORD *)(v1 + 20) )
      v8 = (const char *)trace_print_array_seq(
                           a1 + 136,
                           v1 + *(unsigned __int16 *)(v1 + 24),
                           *(unsigned __int16 *)(v1 + 20),
                           2);
    else
      v8 = (const char *)&unk_12D43;
    trace_event_printf(
      a1,
      "handle = %u flags = 0x%x mem_info_tag = %u\t\tvmid_entries = %u entry_vmid_arr = %s\n",
      v5,
      v6,
      v7,
      v4,
      v8);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
