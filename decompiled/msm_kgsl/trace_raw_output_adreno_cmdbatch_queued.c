__int64 __fastcall trace_raw_output_adreno_cmdbatch_queued(__int64 a1)
{
  _DWORD *v1; // x22
  __int64 result; // x0
  __int64 v4; // x2
  int v5; // w20
  int v6; // w21
  int v7; // w22
  int v8; // w23
  const char *v9; // x6

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = v1[4];
    v4 = (unsigned int)v1[5];
    v6 = v1[6];
    v8 = v1[2];
    v7 = v1[3];
    if ( (_DWORD)v4 )
      v9 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_adreno_cmdbatch_queued___flags);
    else
      v9 = "none";
    trace_event_printf(a1, "ctx=%u ctx_prio=%u ts=%u queued=%u flags=%s\n", v8, v6, v7, v5, v9);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
