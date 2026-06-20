__int64 __fastcall _bpf_trace_rdev_add_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 a5,
        char a6,
        __int64 a7,
        unsigned __int8 a8)
{
  return bpf_trace_run7(a1, a2, a3, a4, a5, a6 & 1, a7, a8);
}
