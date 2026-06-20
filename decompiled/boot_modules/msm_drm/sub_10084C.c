void __fastcall sub_10084C(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x29
  __int64 v3; // x0
  __int64 v4; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v1 + 16);
    *(_QWORD *)(v2 + 24) = a1;
    _traceiter_tracing_mark_write(0, 66, v1, "te_deassert_irq", 0);
    v3 = *(_QWORD *)(v2 + 24);
    v4 = *(_QWORD *)(v1 + 16) - 1LL;
    *(_DWORD *)(v1 + 16) = v4;
    if ( !v4 || !*(_QWORD *)(v1 + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x100800);
}
