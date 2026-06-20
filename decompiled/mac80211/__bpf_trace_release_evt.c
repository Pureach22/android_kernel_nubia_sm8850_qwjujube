__int64 __fastcall _bpf_trace_release_evt(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 a4,
        unsigned int a5,
        unsigned int a6,
        char a7)
{
  return bpf_trace_run6(a1, a2, a3, a4, a5, a6, a7 & 1);
}
