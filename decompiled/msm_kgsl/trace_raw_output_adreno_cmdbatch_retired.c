__int64 __fastcall trace_raw_output_adreno_cmdbatch_retired(__int64 a1)
{
  __int64 v1; // x26
  __int64 result; // x0
  int v4; // w20
  int v5; // w22
  int v6; // w23
  int v7; // w21
  const char *v8; // x24
  __int64 v9; // x2
  const char *v10; // x7

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 16);
    v6 = *(_DWORD *)(v1 + 8);
    v5 = *(_DWORD *)(v1 + 12);
    v7 = *(_DWORD *)(v1 + 48);
    if ( *(_DWORD *)(v1 + 20) )
    {
      v8 = (const char *)trace_print_flags_seq(
                           a1 + 136,
                           "|",
                           *(_QWORD *)(v1 + 72),
                           &trace_raw_output_adreno_cmdbatch_retired___flags);
      v9 = *(unsigned int *)(v1 + 24);
      if ( (_DWORD)v9 )
      {
LABEL_4:
        v10 = (const char *)trace_print_flags_seq(
                              a1 + 136,
                              "|",
                              v9,
                              &trace_raw_output_adreno_cmdbatch_retired___flags_78);
LABEL_7:
        trace_event_printf(
          a1,
          "ctx=%u ctx_prio=%d ts=%u inflight=%d recovery=%s flags=%s start=%llu retire=%llu rb_id=%d, r/w=%x/%x, q_inflig"
          "ht=%d, dq_id=%u, submitted_to_rb=%llu retired_on_gmu=%llu active=%llu\n",
          v6,
          v7,
          v5,
          v4,
          v8,
          v10,
          *(_QWORD *)(v1 + 32),
          *(_QWORD *)(v1 + 40),
          *(_DWORD *)(v1 + 52),
          *(_DWORD *)(v1 + 56),
          *(_DWORD *)(v1 + 60),
          *(_DWORD *)(v1 + 64),
          *(_DWORD *)(v1 + 80),
          *(_QWORD *)(v1 + 88),
          *(_QWORD *)(v1 + 96),
          *(_QWORD *)(v1 + 104));
        return trace_handle_return(a1 + 8352);
      }
    }
    else
    {
      v8 = "none";
      v9 = *(unsigned int *)(v1 + 24);
      if ( (_DWORD)v9 )
        goto LABEL_4;
    }
    v10 = "none";
    goto LABEL_7;
  }
  return result;
}
