__int64 __fastcall _bpf_trace_dfc_qmap(__int64 a1, __int64 a2, __int64 a3, char a4, unsigned __int8 a5)
{
  return bpf_trace_run4(a1, a2, a3, a4 & 1, a5);
}
