__int64 __fastcall trace_raw_output_gh_rm_mem_accept_reply(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  int v4; // w2
  const char *v5; // x3
  const char *v6; // x4
  int v7; // w22
  __int64 v8; // x2
  __int64 v9; // x1
  const char *v10; // x21
  __int64 v11; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 8);
    if ( v4 && (*(_BYTE *)(v1 + 24) & 1) == 0 )
    {
      v7 = *(_DWORD *)(v1 + 8);
      v5 = (const char *)trace_print_array_seq(
                           a1 + 136,
                           v1 + *(unsigned __int16 *)(v1 + 12),
                           *(unsigned int *)(v1 + 20),
                           8);
      if ( *(_DWORD *)(v1 + 8) )
      {
        if ( *(_BYTE *)(v1 + 24) )
        {
          v4 = v7;
          v6 = (const char *)&unk_12D43;
        }
        else
        {
          v8 = *(unsigned int *)(v1 + 20);
          v9 = v1 + *(unsigned __int16 *)(v1 + 16);
          v10 = v5;
          v11 = trace_print_array_seq(a1 + 136, v9, v8, 8);
          v5 = v10;
          v4 = v7;
          v6 = (const char *)v11;
        }
      }
      else
      {
        v6 = (const char *)&unk_12D43;
        v4 = v7;
      }
    }
    else
    {
      v5 = (const char *)&unk_12D43;
      v6 = (const char *)&unk_12D43;
    }
    trace_event_printf(a1, "sgl_entries = %u sgl_ipa_base = %s sgl_size = %s\t\t\n", v4, v5, v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
