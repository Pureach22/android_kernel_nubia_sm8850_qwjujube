void sub_F541C()
{
  __int64 v0; // x29
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x8

  v1 = *(unsigned int *)(*(_QWORD *)(v0 - 64) + 40LL);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v1 >> 3) & 0x1FFFFFF8)) >> v1) & 1) != 0 )
  {
    v2 = *(_QWORD *)(v0 - 64);
    ++*(_DWORD *)(v2 + 16);
    v3 = _traceiter_tracing_mark_write(0, 69, v2, "vblank_irq", 0);
    v4 = *(_QWORD *)(v2 + 16) - 1LL;
    *(_DWORD *)(v2 + 16) = v4;
    if ( !v4 || !*(_QWORD *)(*(_QWORD *)(v0 - 64) + 16LL) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0xF5364);
}
