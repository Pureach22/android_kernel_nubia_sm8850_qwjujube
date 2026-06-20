void __fastcall sub_FE40(__int64 a1, int a2, unsigned __int8 a3, int a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x19
  __int64 v8; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x22
  __int64 (__fastcall *v12)(__int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v13; // x4
  __int64 v14; // x6
  __int64 v15; // x1
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // t1
  __int64 v19; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v8 + 24) = a4;
    *(_DWORD *)(v8 + 28) = a2;
    *(_QWORD *)(v8 - 8) = a5;
    *(_QWORD *)(v8 - 16) = a7;
    ++*(_DWORD *)(StatusReg + 16);
    v11 = qword_14410;
    if ( qword_14410 )
    {
      do
      {
        v12 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64))v11;
        v14 = *(_QWORD *)(v8 - 16);
        v13 = *(_QWORD *)(v8 - 8);
        v16 = *(unsigned int *)(v8 + 24);
        v15 = *(unsigned int *)(v8 + 28);
        v17 = *(_QWORD *)(v11 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != 1140098178 )
          __break(0x8228u);
        a1 = v12(v17, v15, a3, v16, v13, a6, v14, v7);
        v18 = *(_QWORD *)(v11 + 24);
        v11 += 24;
      }
      while ( v18 );
    }
    v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v19;
    if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, *(unsigned int *)(v8 + 28));
  }
  JUMPOUT(0xFE0C);
}
