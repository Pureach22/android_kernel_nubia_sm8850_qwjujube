void __fastcall sub_3A4C4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x20
  __int64 (__fastcall *v6)(__int64, _QWORD, __int64, __int64, _QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // t1
  __int64 v10; // x8
  unsigned int v11; // [xsp+Ch] [xbp+Ch]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v11 = a1;
    *(_QWORD *)(v3 - 8) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_977D8;
    if ( qword_977D8 )
    {
      do
      {
        v6 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, _QWORD))v5;
        v7 = *(_QWORD *)(v5 + 8);
        v8 = *(_QWORD *)(v3 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != -641035679 )
          __break(0x8228u);
        a1 = v6(v7, v11, v8, a3, 0);
        v9 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v9 );
    }
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x3A4B0);
}
