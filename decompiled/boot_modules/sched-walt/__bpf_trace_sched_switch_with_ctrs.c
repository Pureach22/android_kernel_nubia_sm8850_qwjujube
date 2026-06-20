__int64 __fastcall _bpf_trace_sched_switch_with_ctrs(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  return bpf_trace_run3(a1, a2 & 1, a3, a4);
}
