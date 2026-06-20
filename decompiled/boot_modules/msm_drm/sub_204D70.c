void __fastcall sub_204D70(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x0
  __int64 v11; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a10 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a10 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a10 + 16);
    v10 = _traceiter_tracing_mark_write(0, 0x45u, a10, (__int64)"msm_disable", 0);
    v11 = *(_QWORD *)(a10 + 16) - 1LL;
    *(_DWORD *)(a10 + 16) = v11;
    if ( !v11 || !*(_QWORD *)(a10 + 16) )
      preempt_schedule_notrace(v10);
  }
  JUMPOUT(0x2048E8);
}
