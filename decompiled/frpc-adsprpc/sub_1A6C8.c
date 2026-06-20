void __fastcall sub_1A6C8(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5, int a6, unsigned int a7)
{
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x20
  __int64 (__fastcall *v10)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD); // x8
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x4
  __int64 v14; // x6
  __int64 v15; // t1
  __int64 v16; // x8
  unsigned int v17; // [xsp+4h] [xbp+4h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v17 = a1;
    *(_DWORD *)(v7 - 20) = a2;
    *(_QWORD *)(v7 - 16) = a4;
    *(_DWORD *)(v7 - 4) = a6;
    ++*(_DWORD *)(StatusReg + 16);
    v9 = qword_22790;
    if ( qword_22790 )
    {
      do
      {
        v10 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD))v9;
        v11 = *(_QWORD *)(v9 + 8);
        v12 = *(unsigned int *)(v7 - 20);
        v13 = *(_QWORD *)(v7 - 16);
        v14 = *(unsigned int *)(v7 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != 1960556665 )
          __break(0x8228u);
        a1 = v10(v11, v17, v12, a3, v13, a5, v14, a7);
        v15 = *(_QWORD *)(v9 + 24);
        v9 += 24;
      }
      while ( v15 );
    }
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x1A6B4);
}
