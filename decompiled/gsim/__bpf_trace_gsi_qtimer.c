__int64 __fastcall _bpf_trace_gsi_qtimer(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned int a6)
{
  return bpf_trace_run5(a1, a2, a3 & 1, a4, a5, a6);
}
