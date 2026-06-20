__int64 __fastcall _bpf_trace_rdev_tdls_mgmt(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int16 a8,
        unsigned int a9,
        char a10,
        __int64 a11,
        __int64 a12)
{
  return bpf_trace_run11(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 & 1, a11, a12);
}
