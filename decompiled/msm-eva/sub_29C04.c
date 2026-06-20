void sub_29C04()
{
  __int64 v0; // x19
  __int64 v1; // x0
  __int64 v2; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v0 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v0 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v0 + 16);
    v1 = _traceiter_tracing_mark_write(0, 69, v0, "iris_hfi_isr", 0);
    v2 = *(_QWORD *)(v0 + 16) - 1LL;
    *(_DWORD *)(v0 + 16) = v2;
    if ( !v2 || !*(_QWORD *)(v0 + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0x29B7C);
}
