__int64 __fastcall trace_raw_output_sched_switch_with_ctrs(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  __int64 v4; // x8
  int v5; // w20
  __int64 v6; // x0
  const char *v7; // x4
  const char *v8; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_QWORD *)(v1 + 48);
    v5 = *(_DWORD *)(v1 + 8);
    if ( (_BYTE)v4 )
    {
      v6 = trace_print_flags_seq(
             a1 + 136,
             "|",
             (unsigned __int8)*(_QWORD *)(v1 + 48),
             &trace_raw_output_sched_switch_with_ctrs___flags);
      v4 = *(_QWORD *)(v1 + 48);
      v7 = (const char *)v6;
    }
    else
    {
      v7 = "R";
    }
    if ( (v4 & 0x100) != 0 )
      v8 = (const char *)&unk_617A0;
    else
      v8 = (const char *)&unk_626F1;
    trace_event_printf(
      a1,
      "prev_comm=%s prev_pid=%d prev_state=%s%s ==> next_comm=%s next_pid=%d CCNTR=%lu CTR0=%lu CTR1=%lu CTR2=%lu CTR3=%l"
      "u CTR4=%lu CTR5=%lu, CYC: %lu, INST: %lu, STALL: %lu\n",
      (const char *)(v1 + 16),
      v5,
      v7,
      v8,
      (const char *)(v1 + 32),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 104),
      *(_QWORD *)(v1 + 112),
      *(_QWORD *)(v1 + 120),
      *(_QWORD *)(v1 + 128));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
