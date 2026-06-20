void __fastcall sub_676DA4(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  unsigned int v3; // w21
  __int64 v4; // x22
  unsigned int v5; // w23
  unsigned int v6; // w24
  unsigned int v7; // w25
  unsigned __int64 StatusReg; // x26
  __int64 v9; // x27
  __int64 (__fastcall *v10)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _QWORD); // x8
  __int64 v11; // x0
  __int64 v12; // t1
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v9 = qword_A30580;
    if ( qword_A30580 )
    {
      do
      {
        v10 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _QWORD))v9;
        v11 = *(_QWORD *)(v9 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != 53828601 )
          __break(0x8228u);
        a1 = v10(v11, v1, v3, v7, v5, v6, v4, v2);
        v12 = *(_QWORD *)(v9 + 24);
        v9 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x676A90);
}
