void __usercall sub_16654(__int64 a1@<X0>, __int64 a2@<X8>)
{
  int v2; // w9
  int v3; // w10
  __int64 v4; // x21
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x22
  __int64 v7; // x23
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // t1
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v5 + 24) = v3;
    *(_DWORD *)(v5 + 28) = v2;
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_22970;
    if ( qword_22970 )
    {
      do
      {
        v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v11 = *(unsigned int *)(v5 + 24);
        v10 = *(unsigned int *)(v5 + 28);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -1269593251 )
          __break(0x8228u);
        a1 = v8(v9, v4, a2, v10, v11);
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
  JUMPOUT(0x16574);
}
