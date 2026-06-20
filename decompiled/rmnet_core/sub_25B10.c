void __usercall sub_25B10(__int64 a1@<X0>, int a2@<W8>)
{
  int v2; // w9
  __int64 v3; // x20
  unsigned int v4; // w21
  unsigned int v5; // w22
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x24
  __int64 v8; // x25
  __int64 (__fastcall *v9)(__int64, __int64, __int64, _QWORD, _QWORD, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x5
  __int64 v13; // t1
  __int64 v14; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v6 + 24) = a2;
    *(_DWORD *)(v6 + 28) = v2;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_309E8;
    if ( qword_309E8 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, __int64))v8;
        v10 = *(_QWORD *)(v8 + 8);
        v11 = *(unsigned int *)(v6 + 24);
        v12 = *(unsigned int *)(v6 + 28);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -453548182 )
          __break(0x8228u);
        a1 = v9(v10, v3 + 296, v11, v4, v5, v12);
        v13 = *(_QWORD *)(v8 + 24);
        v8 += 24;
      }
      while ( v13 );
    }
    v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v14;
    if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x25A50);
}
