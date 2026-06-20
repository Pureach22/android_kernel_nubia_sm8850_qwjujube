void sub_626D8()
{
  __int64 v0; // x19
  __int64 v1; // x0
  __int64 v2; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v0 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v0 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v0 + 16);
    v1 = _traceiter_tracing_mark_write(0, 0x45u, v0, (__int64)"__power_on_controller_v1", 0);
    v2 = *(_QWORD *)(v0 + 16) - 1LL;
    *(_DWORD *)(v0 + 16) = v2;
    if ( !v2 || !*(_QWORD *)(v0 + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0x625F8);
}
