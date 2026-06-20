void sub_119500()
{
  __int64 v0; // x21
  unsigned int v1; // w23
  __int64 v2; // x27
  __int64 v3; // x0
  __int64 v4; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v2 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v2 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v2 + 16);
    v3 = _traceiter_kgsl_timeline_alloc(0, v1, v0);
    v4 = *(_QWORD *)(v2 + 16) - 1LL;
    *(_DWORD *)(v2 + 16) = v4;
    if ( !v4 || !*(_QWORD *)(v2 + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x119444);
}
