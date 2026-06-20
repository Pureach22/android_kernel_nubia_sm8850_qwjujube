void __fastcall sub_116B74(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x19
  __int64 (__fastcall *v11)(__int64, __int64, __int64, const char *, _QWORD); // x8
  __int64 v12; // x0
  __int64 v13; // t1
  __int64 v14; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a10 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a10 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a10 + 16);
    v10 = qword_29E3D0;
    if ( qword_29E3D0 )
    {
      do
      {
        v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, _QWORD))v10;
        v12 = *(_QWORD *)(v10 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v10 - 4LL) != -641035679 )
          __break(0x8228u);
        a1 = v11(v12, 66, a10, "sde_kms_complete_commit", 0);
        v13 = *(_QWORD *)(v10 + 24);
        v10 += 24;
      }
      while ( v13 );
    }
    v14 = *(_QWORD *)(a10 + 16) - 1LL;
    *(_DWORD *)(a10 + 16) = v14;
    if ( !v14 || !*(_QWORD *)(a10 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x116780);
}
