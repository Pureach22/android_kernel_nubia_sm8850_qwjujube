void __fastcall sub_3ED3C(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x24
  __int64 (__fastcall *v3)(__int64, __int64, __int64, const char *, _QWORD); // x8
  __int64 v4; // x0
  __int64 v5; // t1
  __int64 v6; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v1 + 16);
    v2 = qword_977D8;
    if ( qword_977D8 )
    {
      do
      {
        v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, _QWORD))v2;
        v4 = *(_QWORD *)(v2 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -641035679 )
          __break(0x8228u);
        a1 = v3(v4, 66, v1, "before and after memcpy", 0);
        v5 = *(_QWORD *)(v2 + 24);
        v2 += 24;
      }
      while ( v5 );
    }
    v6 = *(_QWORD *)(v1 + 16) - 1LL;
    *(_DWORD *)(v1 + 16) = v6;
    if ( !v6 || !*(_QWORD *)(v1 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x3EA80);
}
