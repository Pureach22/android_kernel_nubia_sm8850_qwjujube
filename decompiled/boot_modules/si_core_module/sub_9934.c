void __fastcall sub_9934(__int64 a1)
{
  __int64 v1; // x24
  unsigned int v2; // w25
  unsigned __int64 StatusReg; // x20
  unsigned int v4; // w26
  __int64 v5; // x21
  __int64 (__fastcall *v6)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // t1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v4 = a1;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_B9E0;
    if ( qword_B9E0 )
    {
      do
      {
        v6 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))v5;
        v7 = *(_QWORD *)(v5 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 779652135 )
          __break(0x8228u);
        a1 = v6(v7, v1, v2, v4);
        v8 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v8 );
    }
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || (a1 = v4, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x96F4);
}
