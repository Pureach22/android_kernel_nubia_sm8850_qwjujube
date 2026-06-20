__int64 __fastcall sub_40564(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x14

  return _bpf_trace_sched_compute_energy(a1, a2, a3, a4, a5, a6, (v6 >> 36) & 0xFFFFF);
}
