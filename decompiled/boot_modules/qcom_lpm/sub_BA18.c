void __fastcall sub_BA18(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w22
  __int64 v4; // x24
  __int64 v5; // x25
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x21
  __int64 (__fastcall *v9)(__int64, _QWORD, __int64, __int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // t1
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_C5B0;
    if ( qword_C5B0 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64))v7;
        v10 = *(_QWORD *)(v7 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -856827744 )
          __break(0x8228u);
        a1 = v9(v10, v3, v4, a3, v5);
        v11 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v11 );
    }
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xB43C);
}
