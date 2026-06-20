void __fastcall sub_E5458(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  __int64 v15; // x0
  __int64 v16; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a15 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a15 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a15 + 16);
    v15 = _traceiter_tracing_mark_write(0, 69, a15, "sde_encoder_prepare_for_kickoff", 0);
    v16 = *(_QWORD *)(a15 + 16) - 1LL;
    *(_DWORD *)(a15 + 16) = v16;
    if ( !v16 || !*(_QWORD *)(a15 + 16) )
      preempt_schedule_notrace(v15);
  }
  JUMPOUT(0xE52DC);
}
