__int64 __fastcall _bpf_trace_waltgov_next_freq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        char a8,
        char a9,
        unsigned int a10,
        unsigned int a11,
        unsigned int a12,
        unsigned int a13)
{
  return bpf_trace_run12(a1, a2, a3, a4, a5, a6, a7, a8 & 1, a9 & 1, a10, a11, a12, a13);
}
