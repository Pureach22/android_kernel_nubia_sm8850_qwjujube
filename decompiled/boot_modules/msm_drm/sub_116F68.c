void __fastcall sub_116F68(__int64 a1)
{
  __int64 v1; // x29
  unsigned __int64 v2; // x8
  __int64 v3; // x23
  __int64 (__fastcall *v4)(__int64, __int64, __int64, const char *, _QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // t1
  __int64 v8; // x9
  __int64 v9; // x8

  v2 = *(unsigned int *)(*(_QWORD *)(v1 - 8) + 40LL);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v2 >> 3) & 0x1FFFFFF8)) >> v2) & 1) != 0 )
  {
    ++*(_DWORD *)(*(_QWORD *)(v1 - 8) + 16LL);
    v3 = qword_29E3D0;
    if ( qword_29E3D0 )
    {
      do
      {
        v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, _QWORD))v3;
        v5 = *(_QWORD *)(v3 + 8);
        v6 = *(_QWORD *)(v1 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -641035679 )
          __break(0x8228u);
        a1 = v4(v5, 66, v6, "sde_kms_wait_for_commit_done", 0);
        v7 = *(_QWORD *)(v3 + 24);
        v3 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(v1 - 8);
    v9 = *(_QWORD *)(v8 + 16) - 1LL;
    *(_DWORD *)(v8 + 16) = v9;
    if ( !v9 || !*(_QWORD *)(*(_QWORD *)(v1 - 8) + 16LL) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x116D40);
}
