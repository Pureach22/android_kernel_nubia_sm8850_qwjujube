void __usercall sub_9CA0(__int64 a1@<X0>, __int64 a2@<X8>)
{
  int v2; // w9
  __int64 v3; // x10
  int v4; // w11
  unsigned int v5; // w12
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x23
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64, _QWORD, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x3
  __int64 v13; // x5
  __int64 v14; // t1
  __int64 v15; // x8
  unsigned int v16; // [xsp+Ch] [xbp+Ch]
  __int64 v17; // [xsp+10h] [xbp+10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v16 = v5;
    *(_DWORD *)(v6 + 24) = v4;
    v17 = v3;
    *(_DWORD *)(v6 + 28) = v2;
    *(_QWORD *)(v6 - 8) = a2;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_C470;
    if ( qword_C470 )
    {
      do
      {
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64))v8;
        v10 = *(_QWORD *)(v8 + 8);
        v12 = *(unsigned int *)(v6 + 24);
        v11 = *(unsigned int *)(v6 + 28);
        v13 = *(_QWORD *)(v6 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -303637479 )
          __break(0x8228u);
        a1 = v9(v10, v11, v17, v12, v16, v13);
        v14 = *(_QWORD *)(v8 + 24);
        v8 += 24;
      }
      while ( v14 );
    }
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x9A9C);
}
