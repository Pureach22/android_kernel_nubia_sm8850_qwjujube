void __fastcall sub_1526C(__int64 a1)
{
  int v1; // w9
  int v2; // w10
  int v3; // w11
  __int64 v4; // x21
  unsigned int v5; // w22
  __int64 v6; // x25
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x28
  __int64 v9; // x24
  __int64 (__fastcall *v10)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x6
  __int64 v14; // x5
  __int64 v15; // t1
  bool v16; // zf

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v7 - 20) = v2;
    *(_DWORD *)(v7 - 16) = v3;
    *(_DWORD *)(v7 - 12) = v1;
    ++*(_DWORD *)(StatusReg + 16);
    v9 = qword_228D0;
    if ( qword_228D0 )
    {
      do
      {
        v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64))v9;
        v11 = *(_QWORD *)(v9 + 8);
        v13 = *(unsigned int *)(v7 - 16);
        v12 = *(unsigned int *)(v7 - 12);
        v14 = *(unsigned int *)(v7 - 20);
        if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != 381064326 )
          __break(0x8228u);
        a1 = v10(v11, v12, v4, v5, v6, v14, v13);
        v15 = *(_QWORD *)(v9 + 24);
        v9 += 24;
      }
      while ( v15 );
    }
    v16 = *(_QWORD *)(StatusReg + 16) == 1;
    --*(_DWORD *)(StatusReg + 16);
    if ( v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x14D08);
}
