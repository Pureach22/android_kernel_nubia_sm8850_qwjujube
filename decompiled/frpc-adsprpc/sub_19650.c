void __usercall sub_19650(__int64 a1@<X0>, unsigned int a2@<W8>)
{
  __int64 v2; // x9
  unsigned int v3; // w10
  int v4; // w11
  __int64 v5; // x19
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x21
  __int64 (__fastcall *v9)(__int64, _QWORD, __int64, __int64, _QWORD, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x3
  __int64 v12; // x5
  __int64 v13; // t1
  __int64 v14; // x8
  unsigned int v15; // [xsp+4h] [xbp+4h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v6 - 4) = v4;
    v15 = v3;
    *(_QWORD *)(v6 + 24) = v2;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_226F0;
    if ( qword_226F0 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64, _QWORD, __int64))v8;
        v10 = *(_QWORD *)(v8 + 8);
        v11 = *(_QWORD *)(v6 + 24);
        v12 = *(unsigned int *)(v6 - 4);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -19974478 )
          __break(0x8228u);
        a1 = v9(v10, a2, v5, v11, v15, v12);
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
  JUMPOUT(0x19598);
}
