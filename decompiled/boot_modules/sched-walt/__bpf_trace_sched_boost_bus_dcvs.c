__int64 __fastcall _bpf_trace_sched_boost_bus_dcvs(__int64 a1, char a2, char a3, char a4)
{
  return bpf_trace_run3(a1, a2 & 1, a3 & 1, a4 & 1);
}
