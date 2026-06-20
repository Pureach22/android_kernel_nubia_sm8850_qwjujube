__int64 __fastcall trace_raw_output_adreno_cmdbatch_submitted(__int64 a1)
{
  __int64 v1; // x24
  __int64 result; // x0
  __int64 v4; // x2
  int v5; // w20
  int v6; // w22
  int v7; // w23
  int v8; // w21
  const char *v9; // x6

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_DWORD *)(v1 + 16);
    v4 = *(unsigned int *)(v1 + 20);
    v7 = *(_DWORD *)(v1 + 8);
    v6 = *(_DWORD *)(v1 + 12);
    v8 = *(_DWORD *)(v1 + 48);
    if ( (_DWORD)v4 )
      v9 = (const char *)trace_print_flags_seq(a1 + 136, "|", v4, &trace_raw_output_adreno_cmdbatch_submitted___flags);
    else
      v9 = "none";
    trace_event_printf(
      a1,
      "ctx=%u ctx_prio=%d ts=%u inflight=%d flags=%s ticks=%lld time=%lu.%0lu rb_id=%d r/w=%x/%x, q_inflight=%d dq_id=%d\n",
      v7,
      v8,
      v6,
      v5,
      v9,
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
