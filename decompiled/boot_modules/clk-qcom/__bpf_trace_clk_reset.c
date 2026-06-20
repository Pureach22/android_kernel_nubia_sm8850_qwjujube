__int64 __fastcall _bpf_trace_clk_reset(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  return bpf_trace_run3(a1, a2, a3, a4 & 1);
}
