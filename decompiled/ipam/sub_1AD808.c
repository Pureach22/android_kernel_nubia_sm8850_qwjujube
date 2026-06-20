void __fastcall sub_1AD808(__int64 a1)
{
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x24
  unsigned __int16 v3; // w23
  __int64 (__fastcall *v4)(__int64, _QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // t1
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v2 = qword_1F6E88;
    if ( qword_1F6E88 )
    {
      v3 = a1;
      do
      {
        v4 = *(__int64 (__fastcall **)(__int64, _QWORD))v2;
        v5 = *(_QWORD *)(v2 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -1513466811 )
          __break(0x8228u);
        a1 = v4(v5, v3);
        v6 = *(_QWORD *)(v2 + 24);
        v2 += 24;
      }
      while ( v6 );
    }
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x1AD71C);
}
