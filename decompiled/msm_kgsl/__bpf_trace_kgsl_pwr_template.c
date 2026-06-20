__int64 __fastcall _bpf_trace_kgsl_pwr_template(__int64 a1, __int64 a2, char a3)
{
  return bpf_trace_run2(a1, a2, a3 & 1);
}
