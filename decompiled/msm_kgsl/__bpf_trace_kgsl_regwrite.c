__int64 __fastcall _bpf_trace_kgsl_regwrite(__int64 a1, unsigned int a2, unsigned int a3)
{
  return bpf_trace_run2(a1, a2, a3);
}
