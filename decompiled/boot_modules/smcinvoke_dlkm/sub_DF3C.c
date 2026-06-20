void __fastcall sub_DF3C(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v2; // w22
  unsigned __int64 StatusReg; // x19
  __int64 v4; // x20
  __int64 (__fastcall *v5)(__int64, __int64, _QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // t1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_10FF8;
    if ( qword_10FF8 )
    {
      do
      {
        v5 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))v4;
        v6 = *(_QWORD *)(v4 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 1626731627 )
          __break(0x8228u);
        a1 = v5(v6, v1, v2);
        v7 = *(_QWORD *)(v4 + 24);
        v4 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xD4F4);
}
