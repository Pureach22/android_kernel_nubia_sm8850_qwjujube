void __fastcall sub_8348(__int64 a1, int a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x20
  void (__fastcall *v8)(__int64, __int64, __int64, __int64, __int64, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x4
  __int64 v12; // t1
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v5 - 12) = a2;
    *(_QWORD *)(v5 - 8) = a4;
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_8E80;
    if ( qword_8E80 )
    {
      do
      {
        v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v10 = *(unsigned int *)(v5 - 12);
        v11 = *(_QWORD *)(v5 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 893828591 )
          __break(0x8228u);
        v8(v9, a1, v10, a3, v11, a5);
        v12 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x8334);
}
