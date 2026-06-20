void __fastcall sub_151D0(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v2; // x21
  unsigned int v3; // w23
  unsigned int v4; // w25
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x27
  __int64 v7; // x24
  __int64 (__fastcall *v8)(__int64, _QWORD, __int64, _QWORD, _QWORD, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x5
  __int64 v11; // t1
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_226A0;
    if ( qword_226A0 )
    {
      do
      {
        v8 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, _QWORD, __int64))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v10 = *(unsigned int *)(v5 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -1266066563 )
          __break(0x8228u);
        a1 = v8(v9, v1, v2, v4, v3, v10);
        v11 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v11 );
    }
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x14C60);
}
