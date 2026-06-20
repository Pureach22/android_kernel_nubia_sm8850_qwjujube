void __usercall sub_128F0(__int64 a1@<X0>, __int64 a2@<X2>, __int64 a3@<X3>, __int64 a4@<X8>)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x20
  void (__fastcall *v7)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // t1
  __int64 v11; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_QWORD *)(v4 - 8) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_1CE28;
    if ( qword_1CE28 )
    {
      do
      {
        v7 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))v6;
        v8 = *(_QWORD *)(v6 + 8);
        v9 = *(_QWORD *)(v4 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 2120924640 )
          __break(0x8228u);
        v7(v8, a1, v9, a4, a3);
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
  JUMPOUT(0x128DC);
}
