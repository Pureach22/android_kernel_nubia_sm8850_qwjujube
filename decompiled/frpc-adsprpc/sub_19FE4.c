void __usercall sub_19FE4(__int64 a1@<X0>, __int64 a2@<X8>)
{
  unsigned int v2; // w20
  __int64 v3; // x23
  __int64 v4; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v6; // x26
  __int64 (__fastcall *v7)(__int64, _QWORD, __int64, __int64, __int64, _QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // t1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_22830;
    if ( qword_22830 )
    {
      do
      {
        v7 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, _QWORD))v6;
        v8 = *(_QWORD *)(v6 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != -1975536614 )
          __break(0x8228u);
        a1 = v7(v8, v2, v3, v4, a2, 0);
        v9 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v9 );
    }
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x19F74);
}
