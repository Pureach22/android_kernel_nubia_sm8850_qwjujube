__int64 __fastcall _bpf_trace_api_chswitch_done(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  return bpf_trace_run3(a1, a2, a3 & 1, a4);
}
