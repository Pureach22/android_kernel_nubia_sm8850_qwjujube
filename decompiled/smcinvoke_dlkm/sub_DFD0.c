void __fastcall sub_DFD0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x21
  unsigned int v11; // w22
  unsigned int v12; // w23
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x20
  __int64 (__fastcall *v15)(__int64, __int64, __int64, _QWORD, _QWORD); // x8
  __int64 v16; // x0
  __int64 v17; // t1
  __int64 v18; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v14 = qword_11048;
    if ( qword_11048 )
    {
      do
      {
        v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD))v14;
        v16 = *(_QWORD *)(v14 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v14 - 4LL) != 1612932161 )
          __break(0x8228u);
        a1 = v15(v16, a10, v10, v11, v12);
        v17 = *(_QWORD *)(v14 + 24);
        v14 += 24;
      }
      while ( v17 );
    }
    v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v18;
    if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xD728);
}
