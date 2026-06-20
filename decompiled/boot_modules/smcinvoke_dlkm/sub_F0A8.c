void __fastcall sub_F0A8(__int64 a1)
{
  unsigned int v1; // w24
  __int64 v2; // x25
  __int64 v3; // x26
  __int64 v4; // x27
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x23
  __int64 (__fastcall *v7)(__int64, __int64, _QWORD, __int64, __int64); // x8
  __int64 v8; // x0
  __int64 v9; // t1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_11188;
    if ( qword_11188 )
    {
      do
      {
        v7 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64))v6;
        v8 = *(_QWORD *)(v6 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 813982898 )
          __break(0x8228u);
        a1 = v7(v8, v3, v1, v4, v2);
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
  JUMPOUT(0xE974);
}
