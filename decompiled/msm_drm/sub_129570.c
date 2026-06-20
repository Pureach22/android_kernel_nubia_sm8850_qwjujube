void __fastcall sub_129570(int a1)
{
  __int64 v1; // x27
  __int64 v2; // x29
  __int64 v3; // x0
  __int64 v4; // x9
  __int64 v5; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v1 + 16);
    *(_QWORD *)(v2 - 8) = v1;
    *(_DWORD *)(v2 - 12) = a1;
    _traceiter_tracing_mark_write(0, 0x45u, v1, (__int64)"smooth_dimming_backlight_update", 0);
    v3 = *(unsigned int *)(v2 - 12);
    v4 = *(_QWORD *)(v2 - 8);
    v5 = *(_QWORD *)(v4 + 16) - 1LL;
    *(_DWORD *)(v4 + 16) = v5;
    if ( !v5 || !*(_QWORD *)(v1 + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x129400);
}
