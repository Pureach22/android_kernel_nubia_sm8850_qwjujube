void __fastcall sub_17D38(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x20
  __int64 (__fastcall *v8)(__int64, _QWORD, __int64, __int64, __int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // t1
  __int64 v14; // x8
  unsigned int v15; // [xsp+Ch] [xbp+Ch]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v15 = a1;
    *(_QWORD *)(v5 - 16) = a2;
    *(_DWORD *)(v5 - 4) = a4;
    *(_DWORD *)(v5 - 20) = a5;
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_22740;
    if ( qword_22740 )
    {
      do
      {
        v8 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, __int64))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v10 = *(_QWORD *)(v5 - 16);
        v11 = *(unsigned int *)(v5 - 4);
        v12 = *(unsigned int *)(v5 - 20);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -19974478 )
          __break(0x8228u);
        a1 = v8(v9, v15, v10, a3, v11, v12);
        v13 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v13 );
    }
    v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v14;
    if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x17D24);
}
