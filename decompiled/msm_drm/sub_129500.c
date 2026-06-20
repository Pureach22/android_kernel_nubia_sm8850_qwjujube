void sub_129500()
{
  __int64 v0; // x27
  __int64 v1; // x29
  __int64 v2; // x0
  __int64 v3; // x9
  __int64 v4; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v0 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v0 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v0 + 16);
    *(_QWORD *)(v1 - 8) = v0;
    v2 = _traceiter_tracing_mark_write(0, 0x42u, v0, (__int64)"smooth_dimming_backlight_update", 0);
    v3 = *(_QWORD *)(v1 - 8);
    v4 = *(_QWORD *)(v3 + 16) - 1LL;
    *(_DWORD *)(v3 + 16) = v4;
    if ( !v4 || !*(_QWORD *)(v0 + 16) )
      preempt_schedule_notrace(v2);
  }
  JUMPOUT(0x1293EC);
}
