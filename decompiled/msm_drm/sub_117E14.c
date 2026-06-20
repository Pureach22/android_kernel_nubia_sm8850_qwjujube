void __fastcall sub_117E14(
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
        __int64 a14)
{
  __int64 v15; // x20
  void (__fastcall *v16)(__int64, __int64, __int64, const char *, _QWORD); // x8
  __int64 v17; // x0
  __int64 v18; // t1
  __int64 v19; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a14 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a14 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a14 + 16);
    v15 = qword_29E3D0;
    if ( qword_29E3D0 )
    {
      do
      {
        v16 = *(void (__fastcall **)(__int64, __int64, __int64, const char *, _QWORD))v15;
        v17 = *(_QWORD *)(v15 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v15 - 4LL) != -641035679 )
          __break(0x8228u);
        v16(v17, 66, a14, "atomic_check", 0);
        v18 = *(_QWORD *)(v15 + 24);
        v15 += 24;
      }
      while ( v18 );
    }
    v19 = *(_QWORD *)(a14 + 16) - 1LL;
    *(_DWORD *)(a14 + 16) = v19;
    if ( !v19 || !*(_QWORD *)(a14 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x11711C);
}
