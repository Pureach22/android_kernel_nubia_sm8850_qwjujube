__int64 __fastcall _bpf_trace_sched_load_to_gov(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        char a9,
        unsigned int a10,
        __int64 a11,
        unsigned int a12)
{
  return bpf_trace_run11(a1, a2, a3, a4, a5, a6, a7, a8, a9 & 1, a10, a11, a12);
}
