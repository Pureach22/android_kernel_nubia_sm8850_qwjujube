void __fastcall sub_17B14(
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
        __int64 a13)
{
  __int64 v13; // x21
  __int64 v14; // x26
  unsigned int v15; // w27
  unsigned int v16; // w28
  __int64 v17; // x24
  __int64 (__fastcall *v18)(__int64, __int64, __int64, _QWORD, _QWORD); // x8
  __int64 v19; // x0
  __int64 v20; // t1
  __int64 v21; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a13 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a13 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a13 + 16);
    v17 = qword_22920;
    if ( qword_22920 )
    {
      do
      {
        v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD))v17;
        v19 = *(_QWORD *)(v17 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v17 - 4LL) != -1269593251 )
          __break(0x8228u);
        a1 = v18(v19, v13, v14, v15, v16);
        v20 = *(_QWORD *)(v17 + 24);
        v17 += 24;
      }
      while ( v20 );
    }
    v21 = *(_QWORD *)(a13 + 16) - 1LL;
    *(_DWORD *)(a13 + 16) = v21;
    if ( !v21 || !*(_QWORD *)(a13 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x17420);
}
