void __usercall sub_D380(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x9
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x20
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // t1
  __int64 v10; // x8
  __int64 v12; // [xsp+10h] [xbp+10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v12 = v2;
    *(_QWORD *)(v3 - 8) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_11138;
    if ( qword_11138 )
    {
      do
      {
        v6 = *(void (__fastcall **)(__int64, __int64, __int64))v5;
        v7 = *(_QWORD *)(v5 + 8);
        v8 = *(_QWORD *)(v3 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 1969950481 )
          __break(0x8228u);
        v6(v7, v8, v12);
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
  JUMPOUT(0xD350);
}
