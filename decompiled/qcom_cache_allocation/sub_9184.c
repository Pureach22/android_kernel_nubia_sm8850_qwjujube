void __usercall sub_9184(unsigned int a1@<W8>)
{
  unsigned int v1; // w19
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x21
  void (__fastcall *v4)(__int64, _QWORD, _QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // t1
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v3 = qword_A348;
    if ( qword_A348 )
    {
      do
      {
        v4 = *(void (__fastcall **)(__int64, _QWORD, _QWORD))v3;
        v5 = *(_QWORD *)(v3 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != 182912235 )
          __break(0x8228u);
        v4(v5, v1, a1);
        v6 = *(_QWORD *)(v3 + 24);
        v3 += 24;
      }
      while ( v6 );
    }
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x90F4);
}
