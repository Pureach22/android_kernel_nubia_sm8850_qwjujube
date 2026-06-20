void __usercall sub_11368(unsigned int a1@<W8>)
{
  int v1; // w9
  unsigned int v2; // w20
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x25
  __int64 v5; // x26
  void (__fastcall *v6)(__int64, const char *, _QWORD, _QWORD, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x4
  __int64 v9; // t1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v3 - 4) = v1;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_22AB0;
    if ( qword_22AB0 )
    {
      do
      {
        v6 = *(void (__fastcall **)(__int64, const char *, _QWORD, _QWORD, __int64))v5;
        v7 = *(_QWORD *)(v5 + 8);
        v8 = *(unsigned int *)(v3 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 789889902 )
          __break(0x8228u);
        v6(v7, "wait", v2, a1, v8);
        v9 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v9 );
    }
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x11240);
}
