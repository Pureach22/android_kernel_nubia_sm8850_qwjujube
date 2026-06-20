__int64 __fastcall _bpf_trace_waltgov_util_update(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        unsigned int a9,
        unsigned int a10,
        char a11)
{
  return bpf_trace_run10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 & 1);
}
