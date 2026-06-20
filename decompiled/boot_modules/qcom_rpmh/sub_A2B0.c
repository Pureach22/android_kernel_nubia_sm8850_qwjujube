void __fastcall sub_A2B0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  char v5; // w21
  unsigned int v6; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v8; // x24
  __int64 (__fastcall *v9)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v10; // x0
  __int64 v11; // t1
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_D6A0;
    if ( qword_D6A0 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))v8;
        v10 = *(_QWORD *)(v8 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -600119737 )
          __break(0x8228u);
        a1 = v9(v10, v4, v5 & 1, v6);
        v11 = *(_QWORD *)(v8 + 24);
        v8 += 24;
      }
      while ( v11 );
    }
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, a2, a3, a4);
  }
  JUMPOUT(0xA27C);
}
