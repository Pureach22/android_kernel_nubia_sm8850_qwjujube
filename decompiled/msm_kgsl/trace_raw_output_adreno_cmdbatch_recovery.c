__int64 __fastcall trace_raw_output_adreno_cmdbatch_recovery(__int64 a1)
{
  _DWORD *v1; // x22
  __int64 result; // x0
  int v4; // w20
  int v5; // w21
  const char *v6; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = v1[2];
    v5 = v1[3];
    v6 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         (unsigned int)v1[4],
                         &trace_raw_output_adreno_cmdbatch_recovery_symbols);
    trace_event_printf(a1, "ctx=%u ts=%u action=%s\n", v4, v5, v6);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
