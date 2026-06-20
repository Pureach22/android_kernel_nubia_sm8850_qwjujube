void __fastcall sub_CD08(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x20
  void (__fastcall *v7)(__int64, __int64, _QWORD, __int64, _QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // x3
  __int64 v10; // t1
  __int64 v11; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v4 - 4) = a3;
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_10F58;
    if ( qword_10F58 )
    {
      do
      {
        v7 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD))v6;
        v8 = *(_QWORD *)(v6 + 8);
        v9 = *(unsigned int *)(v4 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != -1212185588 )
          __break(0x8228u);
        v7(v8, a1, a2, v9, a4);
        v10 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v10 );
    }
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0xCCF4);
}
