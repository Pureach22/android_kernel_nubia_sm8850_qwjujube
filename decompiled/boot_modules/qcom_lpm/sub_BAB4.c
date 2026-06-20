void __fastcall sub_BAB4(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  unsigned int v3; // w23
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x24
  __int64 (__fastcall *v6)(__int64, _QWORD, __int64, _QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // t1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_C600;
    if ( qword_C600 )
    {
      do
      {
        v6 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD))v5;
        v7 = *(_QWORD *)(v5 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 1850099316 )
          __break(0x8228u);
        a1 = v6(v7, v2, v1, v3);
        v8 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v8 );
    }
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xB448);
}
