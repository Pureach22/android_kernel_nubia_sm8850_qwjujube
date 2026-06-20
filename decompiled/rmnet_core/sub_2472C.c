void __fastcall sub_2472C(__int64 a1)
{
  int v1; // w9
  unsigned int v2; // w19
  unsigned int v3; // w20
  unsigned int v4; // w21
  unsigned int v5; // w22
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x25
  __int64 v8; // x26
  __int64 (__fastcall *v9)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x5
  __int64 v12; // t1
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v6 - 4) = v1;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_30B28;
    if ( qword_30B28 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64))v8;
        v10 = *(_QWORD *)(v8 + 8);
        v11 = *(unsigned int *)(v6 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != 903072645 )
          __break(0x8228u);
        a1 = v9(v10, v5, v4, v3, v2, v11);
        v12 = *(_QWORD *)(v8 + 24);
        v8 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x246F0);
}
