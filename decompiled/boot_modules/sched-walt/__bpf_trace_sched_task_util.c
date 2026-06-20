__int64 __fastcall _bpf_trace_sched_task_util(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        char a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        char a9,
        unsigned int a10,
        unsigned int a11)
{
  return bpf_trace_run10(a1, a2, a3, a4, a5 & 1, a6, a7, a8, a9 & 1, a10, a11);
}
