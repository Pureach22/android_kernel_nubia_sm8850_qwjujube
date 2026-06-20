void __usercall sub_10798(int a1@<W8>)
{
  __int64 v1; // x9
  __int64 v2; // x10
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x22
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // t1
  __int64 v11; // x8
  __int64 v12; // [xsp+8h] [xbp+8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v12 = v2;
    *(_QWORD *)(v3 - 8) = v1;
    *(_DWORD *)(v3 - 12) = a1;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = qword_22880;
    if ( qword_22880 )
    {
      do
      {
        v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))v5;
        v7 = *(_QWORD *)(v5 + 8);
        v8 = *(unsigned int *)(v3 - 12);
        v9 = *(_QWORD *)(v3 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != -1334672243 )
          __break(0x8228u);
        v6(v7, v8, v9, v12);
        v10 = *(_QWORD *)(v5 + 24);
        v5 += 24;
      }
      while ( v10 );
    }
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x10674);
}
