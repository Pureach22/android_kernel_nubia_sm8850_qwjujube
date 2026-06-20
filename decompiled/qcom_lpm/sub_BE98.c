void __usercall sub_BE98(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x21
  __int64 (__fastcall *v5)(__int64, _QWORD, __int64, __int64, __int64); // x8
  __int64 v6; // x0
  __int64 v7; // x4
  __int64 v8; // t1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_QWORD *)(v2 + 24) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_C5B0;
    if ( qword_C5B0 )
    {
      do
      {
        v5 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64))v4;
        v6 = *(_QWORD *)(v4 + 8);
        v7 = *(_QWORD *)(v2 + 24);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != -856827744 )
          __break(0x8228u);
        a1 = v5(v6, 0, 3736076013LL, 3736076013LL, v7);
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
  JUMPOUT(0xBE78);
}
