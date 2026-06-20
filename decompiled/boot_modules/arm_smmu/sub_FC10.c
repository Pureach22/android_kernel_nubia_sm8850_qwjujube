void __usercall sub_FC10(__int64 a1@<X8>)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x23
  __int64 v5; // x24
  void (__fastcall *v6)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // t1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_1CF18;
    if ( qword_1CF18 )
    {
      do
      {
        v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))v5;
        v7 = *(_QWORD *)(v5 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 2120924640 )
          __break(0x8228u);
        v6(v7, a1, v1, v2, v3);
        v8 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v8 );
    }
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0xFBF4);
}
