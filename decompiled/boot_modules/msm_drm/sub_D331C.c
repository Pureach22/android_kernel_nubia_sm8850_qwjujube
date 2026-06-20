void __fastcall sub_D331C(
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
        __int64 a12)
{
  __int64 v12; // x0
  __int64 v13; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a12 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a12 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a12 + 16);
    v12 = _traceiter_tracing_mark_write(0, 69, a12, "sde_crtc_atomic_flush", 0);
    v13 = *(_QWORD *)(a12 + 16) - 1LL;
    *(_DWORD *)(a12 + 16) = v13;
    if ( !v13 || !*(_QWORD *)(a12 + 16) )
      preempt_schedule_notrace(v12);
  }
  JUMPOUT(0xD31A4);
}
