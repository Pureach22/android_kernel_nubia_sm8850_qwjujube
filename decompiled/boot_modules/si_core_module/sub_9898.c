void __fastcall sub_9898(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  unsigned int v13; // w24
  __int64 v14; // x25
  unsigned __int64 StatusReg; // x20
  __int64 v16; // x21
  __int64 (__fastcall *v17)(__int64, __int64, _QWORD, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // t1
  __int64 v20; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v16 = qword_B8A0;
    if ( qword_B8A0 )
    {
      do
      {
        v17 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64))v16;
        v18 = *(_QWORD *)(v16 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v16 - 4LL) != -1677128442 )
          __break(0x8228u);
        a1 = v17(v18, v14, v13, a13);
        v19 = *(_QWORD *)(v16 + 24);
        v16 += 24;
      }
      while ( v19 );
    }
    v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v20;
    if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x8DFC);
}
