void __usercall sub_167FC(__int64 a1@<X0>, int a2@<W8>)
{
  __int64 v2; // x9
  __int64 v3; // x10
  unsigned int v4; // w11
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x20
  void (__fastcall *v8)(__int64, __int64, __int64, __int64, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x3
  __int64 v12; // t1
  __int64 v13; // x8
  unsigned int v15; // [xsp+14h] [xbp+14h]
  __int64 v16; // [xsp+18h] [xbp+18h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v15 = v4;
    *(_QWORD *)(v5 - 16) = v3;
    v16 = v2;
    *(_DWORD *)(v5 - 4) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_227E0;
    if ( qword_227E0 )
    {
      do
      {
        v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v10 = *(unsigned int *)(v5 - 4);
        v11 = *(_QWORD *)(v5 - 16);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 2060387865 )
          __break(0x8228u);
        v8(v9, v10, v16, v11, v15);
        v12 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x167D8);
}
