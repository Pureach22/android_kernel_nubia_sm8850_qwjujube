void __fastcall sub_CEC0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        char a10)
{
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x20
  void (__fastcall *v12)(__int64, char *); // x8
  __int64 v13; // x0
  __int64 v14; // t1
  __int64 v15; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v11 = qword_10B38;
    if ( qword_10B38 )
    {
      do
      {
        v12 = *(void (__fastcall **)(__int64, char *))v11;
        v13 = *(_QWORD *)(v11 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != -110690895 )
          __break(0x8228u);
        v12(v13, &a10);
        v14 = *(_QWORD *)(v11 + 24);
        v11 += 24;
      }
      while ( v14 );
    }
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0xCE7C);
}
