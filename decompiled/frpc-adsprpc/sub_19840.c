void __fastcall sub_19840(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x24
  __int64 v9; // x25
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v11; // x3
  __int64 v12; // x5
  __int64 v13; // x4
  __int64 v14; // x6
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x7
  __int64 v19; // t1
  __int64 v20; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v7 - 20) = a1;
    *(_DWORD *)(v7 - 44) = a2;
    *(_QWORD *)(v7 - 16) = a3;
    *(_QWORD *)(v7 - 8) = a5;
    *(_QWORD *)(v7 - 40) = a4;
    *(_QWORD *)(v7 - 32) = a6;
    *(_QWORD *)(v7 + 24) = a7;
    ++*(_DWORD *)(StatusReg + 16);
    v9 = qword_22A10;
    if ( qword_22A10 )
    {
      do
      {
        v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v9;
        v11 = *(_QWORD *)(v7 - 16);
        v12 = *(_QWORD *)(v7 - 8);
        v13 = *(_QWORD *)(v7 - 40);
        v14 = *(_QWORD *)(v7 - 32);
        v15 = *(_QWORD *)(v9 + 8);
        v16 = *(unsigned int *)(v7 - 20);
        v17 = *(unsigned int *)(v7 - 44);
        v18 = *(_QWORD *)(v7 + 24);
        if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != 1521357619 )
          __break(0x8228u);
        a1 = v10(v15, v16, v17, v11, v13, v12, v14, v18);
        v19 = *(_QWORD *)(v9 + 24);
        v9 += 24;
      }
      while ( v19 );
    }
    v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v20;
    if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x19820);
}
