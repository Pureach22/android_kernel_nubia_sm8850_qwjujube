void __fastcall sub_105CC(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x20
  unsigned __int64 v5; // x8
  __int64 v6; // x21
  __int64 (__fastcall *v7)(__int64, _QWORD, __int64); // x8
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // t1
  __int64 v11; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(unsigned int *)(StatusReg + 40);
  *(_DWORD *)(v3 - 4) = a1;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v5 >> 3) & 0x1FFFFFF8)) >> v5) & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_14550;
    if ( qword_14550 )
    {
      do
      {
        v7 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64))v6;
        v8 = *(_QWORD *)(v6 + 8);
        v9 = *(unsigned int *)(v3 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 887759912 )
          __break(0x8228u);
        a1 = v7(v8, v2, v9);
        v10 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v10 );
    }
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, a2);
  }
  JUMPOUT(0x104A8);
}
