void __fastcall sub_104E8(__int64 a1, int a2, unsigned __int8 a3, int a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x19
  __int64 v8; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x22
  __int64 (__fastcall *v12)(__int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // t1
  __int64 v18; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v8 - 4) = a2;
    *(_DWORD *)(v8 - 20) = a4;
    *(_QWORD *)(v8 - 16) = a5;
    ++*(_DWORD *)(StatusReg + 16);
    v11 = qword_14370;
    if ( qword_14370 )
    {
      do
      {
        v12 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64))v11;
        v13 = *(_QWORD *)(v11 + 8);
        v14 = *(unsigned int *)(v8 - 4);
        v15 = *(unsigned int *)(v8 - 20);
        v16 = *(_QWORD *)(v8 - 16);
        if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != 1140098178 )
          __break(0x8228u);
        a1 = v12(v13, v14, a3, v15, v16, a6, a7, v7);
        v17 = *(_QWORD *)(v11 + 24);
        v11 += 24;
      }
      while ( v17 );
    }
    v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v18;
    if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, *(unsigned int *)(v8 - 4));
  }
  JUMPOUT(0x10478);
}
