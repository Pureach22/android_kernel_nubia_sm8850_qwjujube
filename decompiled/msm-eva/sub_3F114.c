void __fastcall sub_3F114(__int64 a1, __int64 a2, int a3, unsigned int a4, int a5, __int64 a6, int a7)
{
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x20
  _QWORD *v9; // x21
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x5
  __int64 v14; // x7
  __int64 v15; // x3
  __int64 v16; // t1
  __int64 v17; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_QWORD *)(v7 - 16) = a1;
    *(_DWORD *)(v7 - 4) = a3;
    *(_DWORD *)(v7 + 24) = a5;
    *(_DWORD *)(v7 + 28) = a7;
    ++*(_DWORD *)(StatusReg + 16);
    v9 = off_97828;
    if ( off_97828 )
    {
      do
      {
        v10 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64, __int64))*v9;
        v11 = v9[1];
        v12 = *(_QWORD *)(v7 - 16);
        v13 = *(unsigned int *)(v7 + 24);
        v14 = *(unsigned int *)(v7 + 28);
        v15 = *(unsigned int *)(v7 - 4);
        if ( *(_DWORD *)(*v9 - 4LL) != -2023479207 )
          __break(0x8228u);
        a1 = v10(v11, v12, a2, v15, a4, v13, a6, v14);
        v16 = v9[3];
        v9 += 3;
      }
      while ( v16 );
    }
    v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v17;
    if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x3F0FC);
}
