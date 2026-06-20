void __usercall sub_D048(__int64 a1@<X0>, unsigned int a2@<W8>)
{
  unsigned int v2; // w9
  unsigned int v3; // w10
  unsigned int v4; // w11
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x22
  __int64 (__fastcall *v7)(__int64, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // t1
  __int64 v10; // x8
  unsigned int v11; // [xsp+8h] [xbp+8h]
  unsigned int v13; // [xsp+10h] [xbp+10h]
  unsigned int v14; // [xsp+14h] [xbp+14h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v13 = v4;
    v14 = v2;
    v11 = v3;
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_E708;
    if ( qword_E708 )
    {
      do
      {
        v7 = *(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))v6;
        v8 = *(_QWORD *)(v6 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 1777565545 )
          __break(0x8228u);
        a1 = v7(v8, a2, v14, v11, v13);
        v9 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v9 );
    }
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xCFA4);
}
