void __fastcall sub_3EC94(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w21
  __int64 v3; // x22
  __int64 (__fastcall *v4)(__int64, __int64, __int64, const char *, _QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // t1
  __int64 v7; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    v2 = a1;
    ++*(_DWORD *)(v1 + 16);
    v3 = qword_977D8;
    if ( qword_977D8 )
    {
      do
      {
        v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, _QWORD))v3;
        v5 = *(_QWORD *)(v3 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -641035679 )
          __break(0x8228u);
        a1 = v4(v5, 69, v1, "cvp_wait_process_message", 0);
        v6 = *(_QWORD *)(v3 + 24);
        v3 += 24;
      }
      while ( v6 );
    }
    v7 = *(_QWORD *)(v1 + 16) - 1LL;
    *(_DWORD *)(v1 + 16) = v7;
    if ( !v7 || (a1 = v2, !*(_QWORD *)(v1 + 16)) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x3EB60);
}
