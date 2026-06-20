void __fastcall sub_1966EC(unsigned int a1)
{
  __int64 v1; // x22
  __int64 v2; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v1 + 16);
    _traceiter_tracing_mark_write(0, 0x45u, v1, (__int64)"msm_bus_scale_req", 0);
    v2 = *(_QWORD *)(v1 + 16) - 1LL;
    *(_DWORD *)(v1 + 16) = v2;
    if ( !v2 || !*(_QWORD *)(v1 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x196600);
}
