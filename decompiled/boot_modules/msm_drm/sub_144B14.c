void __fastcall sub_144B14(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x24
  __int64 v8; // x0
  __int64 v9; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v6 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v6 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v6 + 16);
    v8 = _traceiter_sde_evtlog(0, v5, v4, a4, v7 + 20);
    v9 = *(_QWORD *)(v6 + 16) - 1LL;
    *(_DWORD *)(v6 + 16) = v9;
    if ( !v9 || !*(_QWORD *)(v6 + 16) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x144A9C);
}
