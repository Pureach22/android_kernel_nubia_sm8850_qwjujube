void __fastcall sub_159D0(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23
  void (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x0
  __int64 v7; // t1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v3 = qword_29840;
    if ( qword_29840 )
    {
      do
      {
        v5 = *(void (__fastcall **)(__int64, __int64, __int64))v3;
        v6 = *(_QWORD *)(v3 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != 1706510518 )
          __break(0x8228u);
        v5(v6, a1, v1);
        v7 = *(_QWORD *)(v3 + 24);
        v3 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x1589C);
}
