void __fastcall sub_206930(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a9 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a9 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a9 + 16);
    _traceiter_tracing_mark_write(0, 0x45u, a9, (__int64)"msm_enable", 0);
    JUMPOUT(0x206980);
  }
  JUMPOUT(0x206708);
}
