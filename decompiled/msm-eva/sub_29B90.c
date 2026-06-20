void __fastcall sub_29B90(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x29
  __int64 v3; // x0
  __int64 v4; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v1 + 16);
    *(_DWORD *)(v2 + 28) = a1;
    _traceiter_tracing_mark_write(0, 66, v1, "iris_hfi_isr", 0);
    v3 = *(unsigned int *)(v2 + 28);
    v4 = *(_QWORD *)(v1 + 16) - 1LL;
    *(_DWORD *)(v1 + 16) = v4;
    if ( !v4 || !*(_QWORD *)(v1 + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x29B74);
}
