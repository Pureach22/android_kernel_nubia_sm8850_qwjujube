void sub_30CD8()
{
  __int64 v0; // x26
  __int64 v1; // x0
  __int64 v2; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v0 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v0 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v0 + 16);
    v1 = _traceiter_tracing_mark_write(0, 66, v0, "__init_resources", 0);
    v2 = *(_QWORD *)(v0 + 16) - 1LL;
    *(_DWORD *)(v0 + 16) = v2;
    if ( !v2 || !*(_QWORD *)(v0 + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0x2F2FC);
}
