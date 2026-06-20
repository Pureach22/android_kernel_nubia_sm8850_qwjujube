void __fastcall sub_BB48(__int64 a1)
{
  unsigned int v1; // w11
  unsigned int v2; // w22
  unsigned int v3; // w25
  __int64 v4; // x28
  __int64 (__fastcall *v5)(__int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // t1
  __int64 v8; // x8
  unsigned __int64 StatusReg; // [xsp+0h] [xbp+0h]
  unsigned int v10; // [xsp+8h] [xbp+8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v10 = v1;
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_C650;
    if ( qword_C650 )
    {
      do
      {
        v5 = *(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))v4;
        v6 = *(_QWORD *)(v4 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != -1663280203 )
          __break(0x8228u);
        a1 = v5(v6, v2, v3, v10);
        v7 = *(_QWORD *)(v4 + 24);
        v4 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xB9C8);
}
