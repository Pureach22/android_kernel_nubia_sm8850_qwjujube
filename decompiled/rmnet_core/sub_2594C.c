void __usercall sub_2594C(__int64 a1@<X0>, int a2@<W8>)
{
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v4; // x20
  void (__fastcall *v5)(__int64, __int64, _QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // t1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v2 - 4) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_30AD8;
    if ( qword_30AD8 )
    {
      do
      {
        v5 = *(void (__fastcall **)(__int64, __int64, _QWORD))v4;
        v6 = *(_QWORD *)(v4 + 8);
        v7 = *(unsigned int *)(v2 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 182912235 )
          __break(0x8228u);
        v5(v6, v7, 0);
        v8 = *(_QWORD *)(v4 + 24);
        v4 += 24;
      }
      while ( v8 );
    }
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x258FC);
}
