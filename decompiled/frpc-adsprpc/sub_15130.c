void __fastcall sub_15130(__int64 a1)
{
  unsigned int v1; // w22
  unsigned int v2; // w25
  unsigned __int64 StatusReg; // x26
  __int64 v4; // x27
  __int64 (__fastcall *v5)(__int64, const char *, _QWORD, _QWORD, _QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // t1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_22AB0;
    if ( qword_22AB0 )
    {
      do
      {
        v5 = *(__int64 (__fastcall **)(__int64, const char *, _QWORD, _QWORD, _QWORD))v4;
        v6 = *(_QWORD *)(v4 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 789889902 )
          __break(0x8228u);
        a1 = v5(v6, "complete", v1, v2, 0);
        v7 = *(_QWORD *)(v4 + 24);
        v4 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x14B0C);
}
