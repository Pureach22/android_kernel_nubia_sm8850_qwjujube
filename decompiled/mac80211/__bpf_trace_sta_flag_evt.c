__int64 __fastcall _bpf_trace_sta_flag_evt(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  return bpf_trace_run4(a1, a2, a3, a4, a5 & 1);
}
