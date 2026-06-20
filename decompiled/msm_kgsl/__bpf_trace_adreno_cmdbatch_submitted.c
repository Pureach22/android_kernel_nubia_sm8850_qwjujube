__int64 __fastcall _bpf_trace_adreno_cmdbatch_submitted(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7)
{
  return bpf_trace_run6(a1, a2, a3, a4, a5, a6, a7);
}
