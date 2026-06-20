void __fastcall sub_9E68(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x20
  void (__fastcall *v8)(__int64, __int64, __int64); // x8
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x0
  __int64 v12; // t1
  bool v13; // zf

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_QWORD *)(v5 - 16) = v4;
    *(_QWORD *)(v5 - 8) = a4;
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_A3E8;
    if ( qword_A3E8 )
    {
      do
      {
        v8 = *(void (__fastcall **)(__int64, __int64, __int64))v7;
        v9 = *(_QWORD *)(v5 - 16);
        v10 = *(_QWORD *)(v5 - 8);
        v11 = *(_QWORD *)(v7 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 1832040158 )
          __break(0x8228u);
        v8(v11, v9, v10);
        v12 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(StatusReg + 16) == 1;
    --*(_DWORD *)(StatusReg + 16);
    if ( v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, a2, a3, *(_QWORD *)(v5 - 8));
  }
  JUMPOUT(0x9DEC);
}
